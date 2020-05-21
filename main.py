from autogen import init
from autogen.vdcl import vdcl

import logging


def main():
    dic = vdcl.getRamVariableDict()
    vdcl.genarateRamVdclFiles(dic)
    vdcl.InsertRamVdclVars()

if __name__ == "__main__":
    main()
