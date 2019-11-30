#include "Simple_Digits.h"

std::vector<size_t> Simple_Digits_Singleton::prime_div(size_t value)
{
  size_t div = 2;
  std::vector<size_t> div_arr;

  try
  {
    while (value > 1)
    {

      while (value % div == 0)
      {

        div_arr.push_back(div);
        value = value / div;
      }
      div = /*prime_singleton->getInstance().*/next_simple(div);
    }

    std::cout << std::endl;
    for (auto t : div_arr)
    {
      std::cout << t << "  ";
    }
    std::cout << std::endl;
  }
  catch (std::exception& ex)
  {
    std::cout << ex.what() << std::endl;
  }
  return std::move(div_arr);

}

Simple_Digits_Singleton::Simple_Digits_Singleton(size_t n)
{
  size_t size = n + 1;
  _simple_digits_cache.reserve(size/2);

  _simple_digits_cache = sieve_eratosthenes(size);
  
  #ifdef DEBUG_PRIME
    std::cout << std::endl;
    for (auto t : _simple_digits_cache)
    {
      std::cout << t << "  " ;
    }
    std::cout<<std::endl;
  #endif
}

bool Simple_Digits_Singleton::is_simple(size_t value)
{
  if (std::find(begin(_simple_digits_cache), end(_simple_digits_cache), value) != end(_simple_digits_cache))
  {
    #ifdef DEBUG_PRIME
      std::cout << "(from cache) ";
    #endif
    return true;
  }
  else
  {
    if (check_simple(value))
    {
      std::lock_guard lock(_cache_lock);
      _simple_digits_cache.push_back(value);
      return true;
    }
    
    return false;
  }
}

size_t Simple_Digits_Singleton::next_simple(size_t prev)
{
  if (auto current = std::upper_bound(begin(_simple_digits_cache), end(_simple_digits_cache), prev); current != end(_simple_digits_cache))
  {
    return *current;
  }
  else
  {
    auto simple = 0;
    while (1)
    {
      if (check_simple(++prev))
      {
        _simple_digits_cache.push_back(prev);
        return prev;
      }
    }
  }
}

bool Simple_Digits_Singleton::check_simple(size_t value)
{
  if (value == 1)
  {
    return false;
  }
      
  for (size_t d = 2; d * d <= value; ++d) 
  {
    if (value % d == 0)
      return false;
  }
  
  return true;  
}

std::vector<size_t> Simple_Digits_Singleton::sieve_eratosthenes(size_t size)
{
  std::vector<size_t> temp(size);
  std::vector<size_t> result;
  result.reserve(1000);
 
  for (size_t i = 0; i < size; ++i)
  {
    temp[i] = i;
  }
  
  for (size_t i = 2 ; i < size; ++i)
  {
    if (temp[i])
    {
      result.push_back(temp[i]);
      for (size_t j = i * i; j < size; j += i)
        temp[j] = 0;
    }
  }

  return std::move(result);
}

