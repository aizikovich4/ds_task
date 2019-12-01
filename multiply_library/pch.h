#pragma once
// add headers that you want to pre-compile here
#include "framework.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <shared_mutex>

//#include <execution>

namespace divides
{


  using std::cout;
  using std::endl;

#define nDEBUG_PRIME
  constexpr unsigned int default_sieve_count = 100;
}