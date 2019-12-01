// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "multiply_library.h"
#include "pch.h"
#include "Simple_Divides.h"
#include <pybind11/pybind11.h>


namespace divides {
  bool divides::get_divides(int* data, int size, char* name)
  {
    Simple_Divides prime;

    for (int i = 0; i < size; ++i)
    {
      auto test = prime.prime_div(data[i]);


    }

    return true;

  }
}



namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}

PYBIND11_MODULE(multiply_library, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  m.def("add", &add, "A function which adds two numbers");
  //m.def("get_divides", &divides::get_divides, "!!! BORIS FUNCTION");
}

