#pragma once
#include "pch.h"
#include "Sieve_Eratosthenes_Singleton.h"
namespace prime_divides {
  class Simple_Divides
  {
  public:
    Simple_Divides() {};

    std::vector<size_t> prime_div(size_t value);
    bool is_simple(size_t);

  private:

    size_t next_simple(size_t& prev);

    std::map<size_t, std::vector<size_t>> _prime_cache;

    Sieve_Eratosthenes_Singleton* sieve;

    Simple_Divides(const Simple_Divides&) = delete;
    Simple_Divides(Simple_Divides&&) = delete;
    Simple_Divides& operator=(Simple_Divides&) = delete;
  };
}