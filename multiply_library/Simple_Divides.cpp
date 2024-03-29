#include "Simple_Divides.h"

namespace prime_divides {
  std::vector<size_t> Simple_Divides::prime_div(size_t value)
  {
    if (_prime_cache.count(value))
    {
      return _prime_cache[value];
    }

    size_t div = 2;
    auto source_value = value;
    std::vector<size_t> div_arr;

    if (sieve->getInstance().is_simple(value))
    {
      return {};
    }

    try
    {
      while (value > 1)
      {

        while (value % div == 0)
        {

          div_arr.push_back(div);
          value = value / div;
        }
        div = sieve->getInstance().next_simple(div);
      }

#ifdef DEBUG_PRIME
      std::cout << "Prime dividers for " << source_value << std::endl;
      for (auto t : div_arr)
      {
        std::cout << t << "  ";
      }
      std::cout << std::endl;
#endif
    }
    catch (std::exception& ex)
    {
      std::cout << ex.what() << std::endl;
    }

    _prime_cache[value] = div_arr;

    return std::move(div_arr);
  }

  bool Simple_Divides::is_simple(size_t number)
  {
    return sieve->getInstance().is_simple(number);
  }

 }