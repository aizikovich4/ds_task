// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "multiply_library.h"
#include "pch.h"
#include "Simple_Divides.h"
#include <pybind11/pybind11.h>


namespace divides {
  std::vector<size_t> get_divides(size_t n)
  {
    Simple_Divides prime;

    auto test = prime.prime_div(n);
    return test;
  }

}



namespace py = pybind11;

int add(int i, int j) {
  return i + j;
}

PYBIND11_MODULE(multiply_library, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  m.def("add", &add, "A function which adds two numbers");
}

