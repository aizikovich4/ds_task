// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "multiply_library.h"
#include "pch.h"
#include "Simple_Divides.h"

/*
namespace divides {
  bool divides::get_divides(const py::list& items, char* name)
  {
    Simple_Divides prime;

    for (auto t : items)
    {
      //in this place we can parallel our calculates
      auto test = prime.prime_div(t);
    }
    
    return true;

  }
}*/



pybind11::object get_random(const pybind11::list& items, const pybind11::object& value) {
  if (items.size()) {    
    return value;
  }
  else {
    return pybind11::none();
  };
}
int add(int i, int j) {
  return i + j;
}

PYBIND11_MODULE(multiply_library, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  m.def("add", &add, "A function which adds two numbers");
  m.def("get_random", &get_random);
  //m.def("get_divides", &divides::get_divides, "!!! BORIS FUNCTION");
}

