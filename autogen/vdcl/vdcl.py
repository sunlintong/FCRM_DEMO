# conding=utf8
import logging
import os
import re

from jinja2 import Environment, PackageLoader

from autogen.init import base
from autogen.vdcl import ram

# 变量名为key，用于在.c文件中匹配变量
RamVariableDict = {}
# 文件名为key，用于生成vdcl.h文件
RamFileDict = {}

vdclOutputDir = os.path.join(base.autogenDir, "inc", "vdcl")


def InsertRamVdclVars():
    ramVarDict = getRamVariableDict()
    for path in getFilePathsToInsertRamVdcl():
        # mode: r+, 读写
        file = open(path, mode="r+", encoding="gbk")
        content = file.read()
        file.seek(0)  # 光标移回首部，便于下次读取

        parameterReg = re.compile(r'[a-zA-Z_][a-zA-Z0-9_]*', re.S)
        varIter = re.finditer(parameterReg, content)
        # 相同vdcl的头文件只能include一次，用set避免重复
        includeSet = set()

        # 拼接植入代码
        VdclInsertContent = ""
        IncludeInsertContent = ""
        for var in varIter:
            if var.group() in ramVarDict:
                logging.debug(f"{var.group()} match in {path}")
                ramVar = ramVarDict[var.group()]

                if ramVar.filePath not in includeSet:
                    IncludeInsertContent += ramVar.getIncludeExpression()
                    includeSet.add(ramVar.filePath)

                VdclInsertContent += ramVar.getVdclDefineName()

        lines = file.readlines()

        # file.seek(0)
        # XXX 关闭文件后再打开，不知道为什么，用file.seek(0)移动光标后，会多写一些代码
        file.close()
        file = open(path, mode="w", encoding="gbk")

        flag = False
        for i in range(len(lines)):
            if re.match(r'.*declaration.*begin.*', lines[i]):
                i += 1  # i+1，否则会插到上面一行，导致下次又匹配到
                lines.insert(i, VdclInsertContent)
                logging.info(f"insert VDCL declare in file: {path}:{i}")
                flag = True
                break

        if not flag:
            logging.warning(f"{path} not find [declaration begin]")
        file.write("".join(lines))
        file.close()

        flag = False
        file = open(path, mode="w", encoding="gbk")
        for i in range(len(lines)):
            if re.match(r'.*header.*definition.*begin.*', lines[i]):
                i += 1  # i+1，否则会插到上面一行，导致下次又匹配到
                lines.insert(i, IncludeInsertContent)
                logging.info(f"insert include declare in file: {path}:{i}")
                flag = True

                break

        if not flag:
            logging.warning(f"{path} not find [header definition begin]")
        file.write("".join(lines))
        file.close()


def genarateRamVdclFiles(dict):
    env = Environment(loader=PackageLoader("autogen.vdcl"))
    template = env.get_template("ram.vdcl.h.j2")

    if not os.path.exists(vdclOutputDir):
        os.makedirs(vdclOutputDir)

    for key in RamFileDict.keys():
        content = template.render(
            header=RamFileDict[key][0].formatVdclHeaderName(), ramList=RamFileDict[key])

        outputFile = os.path.join(
            vdclOutputDir, RamFileDict[key][0].getFileBaseName() + ".vdcl.h")

        # mode: w, 覆盖写入
        file = open(outputFile, mode="w", encoding="gbk")
        file.write(content)
        file.close()
        logging.info("%s 生成成功", outputFile)


def getRamFilePaths():
    L = []
    for root, dirs, files in os.walk(base.autogenDir):
        for file in files:
            filePath = os.path.join(root, file)
            if filePath.endswith("ram.c"):
                L.append(filePath)
    logging.debug("ram.c files: %s", ", ".join(L))
    return L


def getFilePathsToInsertRamVdcl():
    L = []
    for root, dirs, files in os.walk(base.autogenDir):
        for file in files:
            filePath = os.path.join(root, file)
            if not filePath.endswith("ram.c") and not filePath.endswith(".h"):
                L.append(filePath)
    logging.debug("files to insert ram vdcl: %s", ", ".join(L))
    return L


def initRamDicts():
    """
    初始化两个dict:
    RamVariableDict
    RamFileDict
    """
    RamVariableDict.clear()
    RamFileDict.clear()

    ramFilePaths = getRamFilePaths()
    for filePath in ramFilePaths:
        file = open(filePath, encoding="gbk")

        # 用来保存每个文件的ramObj
        ramObjList = []
        lines = file.readlines()
        # count记录每个文件的变量个数
        count = 0

        for line in lines:
            # 匹配以;结尾的
            # TODO 匹配每一行的注释，也一起插入
            if re.match(r'(.*;)', line):
                if re.match(r'(^ *)//', line):
                    # (^ *)// 匹配以//开头的，避免将这些也计算在内：
                    # //word32 claw_pre_heart[4];
                    #  // int16  	ivot_dummy;
                    continue

                #  移除 ";"，以便分割提取字符串
                line = line.replace(";", " ")
                words = line.split()
                # words[0]: 变量类型
                # words[1]: 变量名
                if words[1] in RamVariableDict:
                    raise RuntimeError(
                        f"变量: {words[0]} {words[1]}已在文件: {RamVariableDict[words[1]].filePath}中声明")
                if len(words) >= 2:
                    varType = words[0]
                    varName = words[1]
                    parameter = ""

                    # 针对这种：int16	out_cmd_lst[OUT_CMD_NUM];
                    # 提取[OUT_CMD_NUM]为parameter
                    # 提取out_cmd_lst为varName
                    parameterReg = re.compile(r'\[.*\]', re.S)
                    tmp = re.findall(parameterReg, varName)
                    if len(tmp) > 0:
                        parameter = tmp[0]
                        varName = re.sub(parameterReg, "", varName)

                    ramObj = ram.Ram(varName=varName, varType=varType,
                                     parameter=parameter, filePath=filePath)
                    # 变量名唯一，用来做key
                    RamVariableDict[words[1]] = ramObj
                    ramObjList.append(ramObj)

        RamFileDict[filePath] = ramObjList


def getRamVariableDict():
    if len(RamVariableDict) == 0:
        initRamDicts()
    return RamVariableDict


def getRamFileDict():
    if len(RamFileDict) == 0:
        initRamDicts()
    return RamFileDict
