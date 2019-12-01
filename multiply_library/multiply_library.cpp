// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "multiply_library.h"
#include "pch.h"
#include "Simple_Divides.h"


using namespace divides;

bool get_divides(const std::vector<int>& items, char* name)
{
  Simple_Divides prime;

  for (size_t i=0; i<items.size(); ++i)
  {
    //in this place we can parallel our calculates

    auto test = prime.prime_div(items[i]);
  }

  return true;

}




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
  m.def("get_divides",&divides::get_divides, "!!! BORIS FUNCTION");
}

