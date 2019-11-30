#pragma once
#include "stdafx.h"
#include "Sieve_Eratosthenes_Singleton.h"

class Simple_Divides
{
public:
  Simple_Divides() {};
   
  std::vector<size_t> prime_div(size_t value);

private:
  
  size_t next_simple(size_t& prev);

  Sieve_Eratosthenes_Singleton* sieve;

  Simple_Divides(const Simple_Divides&) = delete;
  Simple_Divides(Simple_Divides&&) = delete;
  Simple_Divides& operator=(Simple_Divides&) = delete;

};

