#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <mutex>
#include <shared_mutex>

using std::cout;
using std::endl;

#define DEBUG_PRIME
constexpr unsigned int default_sieve_count = 100;