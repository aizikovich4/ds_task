// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "multiply_library.h"
#include "pch.h"
#include "Simple_Divides.h"


MULTIPLYLIBRARY_API bool check(void)
{
  return true;
}

std::vector<size_t> get_divides(size_t n)
{
  Simple_Divides prime;

  auto test = prime.prime_div(n);
  return test;
}


// This is the constructor of a class that has been exported.
Cmultiplylibrary::Cmultiplylibrary()
{
    return;
}
