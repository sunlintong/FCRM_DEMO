# conding=utf8
import os


class Ram:
    def __init__(self, varName="", varType="", parameter="", filePath=""):
        self.varName = varName
        self.varType = varType
        self.parameter = parameter
        self.filePath = filePath

    def getFileBaseName(self):
        tmp = self.filePath.split(os.sep)[-1]
        return tmp.split(".")[0]

    def getVdclDefineName(self):
        return "VDCL_{};\n".format(self.varName)

    def getIncludeExpression(self):
        return '#include "vdcl{0}{1}.vdcl.h"\n'.format(os.sep, self.getFileBaseName())

    def formatVdclHeaderName(self):
        return "{}_VDCL_H_".format(self.getFileBaseName().upper())
