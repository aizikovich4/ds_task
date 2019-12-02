import os, sys

from distutils.core import setup, Extension
from distutils import sysconfig

cpp_args = ['/std:c++17']

class get_pybind_include(object):
    """Helper class to determine the pybind11 include path
    The purpose of this class is to postpone importing pybind11
    until it is actually installed, so that the ``get_include()``
    method can be invoked. """

    def __init__(self, user=False):
        self.user = user

    def __str__(self):
        import pybind11
        return pybind11.get_include(self.user)
		
sfc_module = Extension(
    'multiply_library', sources = ['multiply_library.cpp','Sieve_Eratosthenes_Singleton.cpp','Simple_Divides.cpp'],
    include_dirs=[get_pybind_include(), get_pybind_include(user=True), os.getcwd()],
    language='c++',
    extra_compile_args = cpp_args,
    )

setup(
    name = 'multiply_library',
    version = '1.0',
    description = 'Dino systems test task - calculate prime divides and output to file',
    ext_modules = [sfc_module],
)