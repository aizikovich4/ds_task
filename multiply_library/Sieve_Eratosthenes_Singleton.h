#pragma once
#include "pch.h"

class Sieve_Eratosthenes_Singleton
{
public:

  static Sieve_Eratosthenes_Singleton& getInstance() {
    static Sieve_Eratosthenes_Singleton  instance(default_sieve_count);
    return instance;
  }

  bool check_simple(size_t value);
  bool get_next(size_t& value, size_t& next);

private:

  std::mutex _prime_table_lock;
  std::vector<size_t> _prime_numbers;



  Sieve_Eratosthenes_Singleton(size_t count=100);
  Sieve_Eratosthenes_Singleton() = delete;
  Sieve_Eratosthenes_Singleton(const Sieve_Eratosthenes_Singleton&) = delete;
  Sieve_Eratosthenes_Singleton& operator=(Sieve_Eratosthenes_Singleton&) = delete;


};

