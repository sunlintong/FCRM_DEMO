import os
import shutil
import logging

autogenDir = "tmp"

def initLogging():
   logging.basicConfig(level=logging.WARNING, 
        # datefmt='%Y-%m-%d %H:%M:%S',
        format="%(levelname)s %(asctime)s [%(filename)s:%(lineno)d] %(message)s")

def copySrc():
    if os.path.exists(autogenDir):
        shutil.rmtree(autogenDir)
        logging.debug("remove dir: %s", autogenDir)    


    shutil.copytree("src", autogenDir)
    logging.debug("copy src to %s", autogenDir)