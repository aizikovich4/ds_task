import os, sys
import platform

from distutils.core import setup, Extension
from distutils import sysconfig



if platform.system() == "Linux":
    cpp_args = ['-std=c++17']
    sources = ['../multiply_library/prime_divides.cpp', '../multiply_library/Sieve_Eratosthenes_Singleton.cpp',
               '../multiply_library/Simple_Divides.cpp']
else:
    cpp_args = ['/std:c++17']
    sources = ['..\multiply_library\prime_divides.cpp', '..\multiply_library\Sieve_Eratosthenes_Singleton.cpp',
               '..\multiply_library\Simple_Divides.cpp']
class get_pybind_include(object):
    def __init__(self, user=False):
        self.user = user

    def __str__(self):
        import pybind11
        return pybind11.get_include(self.user)
		
sfc_module = Extension(
    'prime_divides', sources,
    include_dirs=[get_pybind_include(), get_pybind_include(user=True), os.getcwd()],
    language='c++',
    extra_compile_args = cpp_args,
    )

setup(
    name = 'prime_divides',
    version = '1.0',
    description = 'Dino systems test task - calculate prime divides and output to file',
    ext_modules = [sfc_module],
)