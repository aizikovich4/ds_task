#include "Sieve_Eratosthenes_Singleton.h"


  Sieve_Eratosthenes_Singleton::Sieve_Eratosthenes_Singleton(size_t count)
  {
    std::vector<size_t> temp(count);

    _prime_numbers.reserve(1000);

    for (size_t i = 0; i < count; ++i)
    {
      temp[i] = i;
    }

    for (size_t i = 2; i < count; ++i)
    {
      if (temp[i])
      {
        _prime_numbers.push_back(temp[i]);
        for (size_t j = i * i; j < count; j += i)
          temp[j] = 0;
      }
    }

#ifdef DEBUG_PRIME
    std::cout << "Prime numbers cache" << std::endl;
    for (auto t : _prime_numbers)
    {
      std::cout << t << "  ";
    }
    std::cout << std::endl;
#endif

  }

  bool Sieve_Eratosthenes_Singleton::calculate_simple(size_t& value)
  {
    if (value == 1)
    {
      return false;
    }

    {
      std::lock_guard<std::mutex> lock(_prime_table_lock);
      if (std::find(/*std::execution::par_unseq,*/ begin(_prime_numbers), end(_prime_numbers), value) != end(_prime_numbers))
      {
        return true;
      }
    }

    for (size_t d = 2; d * d <= value; ++d)
    {
      if (value % d == 0)
        return false;
    }

    {
      std::lock_guard<std::mutex> lock(_prime_table_lock);
      _prime_numbers.push_back(value);
    }
    

    return true;
  }

  size_t Sieve_Eratosthenes_Singleton::next_simple(size_t& prev)
  {
    size_t next = 0;
    if (get_next_from_cache(prev, next))
    {
      return next;
    }
    else
    {
      auto simple = 0;
      while (1)
      {
        if (calculate_simple(++prev))
        {
          return prev;
        }
      }
    }  
  }

  bool Sieve_Eratosthenes_Singleton::get_next_from_cache(size_t& value, size_t& next)
  {
    std::lock_guard<std::mutex> lock(_prime_table_lock);
    auto current = std::upper_bound(begin(_prime_numbers), end(_prime_numbers), value);
    if ( current != end(_prime_numbers))
    {
      next = *current;
      return true;
    }
    else
    {
      return false;
    }
  }

  bool Sieve_Eratosthenes_Singleton::is_simple(size_t& value)
  {
    return calculate_simple(value);
  }
