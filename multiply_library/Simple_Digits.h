#pragma once
#include "stdafx.h"

class Simple_Digits_Singleton
{
public:
  bool is_simple(size_t value);
  
  static Simple_Digits_Singleton& getInstance() {
    static Simple_Digits_Singleton  instance(100);
    return instance;
  };
  
  std::vector<size_t> prime_div(size_t value);
  
private:
  Simple_Digits_Singleton(size_t size = 100);
  size_t next_simple(size_t prev);
  std::vector<size_t> _simple_digits_cache;

  std::vector<size_t> sieve_eratosthenes(size_t n);
  bool check_simple(size_t value);

  std::mutex _cache_lock;


  Simple_Digits_Singleton(const Simple_Digits_Singleton&) = delete;
  Simple_Digits_Singleton(Simple_Digits_Singleton&&) = delete;

};

