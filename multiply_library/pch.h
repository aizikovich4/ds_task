#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <fstream>
#include <map>
#include <pybind11/pybind11.h>

#include <execution>

  using std::cout;
  using std::endl;

#define nDEBUG_PRIME
  constexpr unsigned int default_sieve_count = 10; 
