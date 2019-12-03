#include "prime_divides.h"
#include "pch.h" 
#include "Simple_Divides.h"

namespace prime_divides { 
  std::vector<size_t> get_divides(const size_t number)
  {
    std::ofstream out;
    out.open("primedivides.log");

    try
    {
      Simple_Divides prime;

      if (prime.is_simple(number))
      {
        return {};
      } 

      return prime.prime_div(number);

    }
    catch (std::exception& ex)
    {
      out << ex.what();
      out.close();
    }

    return {};
  }

  PYBIND11_MODULE(prime_divides, m) 
  {
    m.doc() = "prime divedes plugin"; // optional module docstring
    m.def("get_divides", &get_divides);
  }
}
