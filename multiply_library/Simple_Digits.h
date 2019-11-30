#pragma once
#include "stdafx.h"

class Simple_Digits_Singleton
{
public:
  bool is_simple(size_t value);
  size_t get_simple(size_t i);

  static Simple_Digits_Singleton& getInstance() {
    static Simple_Digits_Singleton  instance(100'000'0000);
    return instance;
  }
  size_t next_simple(size_t prev);
  
private:
  Simple_Digits_Singleton(size_t size = 100);
  size_t get_max();  
  std::vector<size_t> _simple_digits_cache;
  size_t _max_value = 0;
  Simple_Digits_Singleton(const Simple_Digits_Singleton&) = delete;
  Simple_Digits_Singleton(Simple_Digits_Singleton&&) = delete;
  std::vector<size_t> sieve_eratosthenes(size_t n);
  bool check_simple(size_t value);

  std::mutex _cache_lock;
  
};

