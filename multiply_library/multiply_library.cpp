// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "multiply_library.h"
#include "pch.h"
#include "Simple_Divides.h"


namespace divides {
  std::vector<size_t> get_divides(size_t n)
  {
    Simple_Divides prime;

    auto test = prime.prime_div(n);
    return test;
  }

}