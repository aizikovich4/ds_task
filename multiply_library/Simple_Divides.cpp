#include "Simple_Divides.h"


std::vector<size_t> Simple_Divides::prime_div(size_t value)
{
  size_t div = 2;
  auto source_value = value;
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
      div = next_simple(div);
    }

    #ifdef DEBUG_PRIME
        std::cout<<"Prime dividers for "<< source_value << std::endl;
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
  return std::move(div_arr);
}

size_t Simple_Divides::next_simple(size_t& prev)
{
  size_t next = 0;
  if (sieve->getInstance().get_next(prev, next))
  {
    return next;
  }
  else
  {
    auto simple = 0;
    while (1)
    {
      if (sieve->getInstance().check_simple(++prev))
      {
        return prev;
      }
    }
  }
}


