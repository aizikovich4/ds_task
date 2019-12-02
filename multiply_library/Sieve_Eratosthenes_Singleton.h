#pragma once
#include "pch.h"
namespace prime_divides {
  class Sieve_Eratosthenes_Singleton
  {
  public:
    static Sieve_Eratosthenes_Singleton& getInstance() {
      static Sieve_Eratosthenes_Singleton  instance(default_sieve_count);
      return instance;
    }

    bool    calculate_simple(size_t& value);
    size_t  next_simple(size_t& prev);
    bool    is_simple(size_t value);
  
  private:
    bool get_next_from_cache(size_t& value, size_t& next);
    std::mutex _prime_table_lock;
    std::vector<size_t> _prime_numbers;

    Sieve_Eratosthenes_Singleton(size_t count = 10);
    Sieve_Eratosthenes_Singleton() = delete;
    Sieve_Eratosthenes_Singleton(const Sieve_Eratosthenes_Singleton&) = delete;
    Sieve_Eratosthenes_Singleton& operator=(Sieve_Eratosthenes_Singleton&) = delete;


  };

}