#pragma once
#include "stdafx.h"

class Simple_Digits
{
public:
  Simple_Digits(size_t size = 100);
  bool is_simple(size_t value);
  
private:
  size_t get_max();

  std::vector<size_t> _simple_digits_cache;
  size_t _max_value = 0;
  Simple_Digits(const Simple_Digits&) = delete;
  Simple_Digits(Simple_Digits&&) = delete;
  std::vector<size_t> sieve_eratosthenes(size_t n);
  bool check_simple(size_t value);

  std::mutex _cache_lock;
  
};

