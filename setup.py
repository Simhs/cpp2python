from distutils.core import setup
from distutils.core import Extension
MODULE_NAME = "mylib"
module = Extension(MODULE_NAME,sources = ["mylib.cpp"])

setup(name=MODULE_NAME,
      version = "1.0",
      ext_modules=[module]
     )
