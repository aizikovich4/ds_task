// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "prime_divides.h"
#include "pch.h" 
#include "Simple_Divides.h"
namespace prime_divides {
  bool write_divides_to_File(const std::vector<size_t> items, const std::string& output_file_name)
  {
    if (output_file_name.empty() || items.empty())
    {
      return false;
    }

    try
    {
      Simple_Divides prime;
      std::map<size_t, std::vector<size_t>> result;

      for (size_t i = 0; i < items.size(); ++i)
      {
        if (!result.count(items[i]))
        {
          //in this place we can parallel our calculates
          result.insert({ items[i], prime.prime_div(items[i]) });
        }

      }

      std::ofstream out;

      out.open(output_file_name);

      for (auto& data : result)
      {
        out << data.first<< " = 1";
        for (auto& d : data.second)
        {
          out << " * " << d;
        }
        out << endl;
      }
    }
    catch (std::exception& ex)
    {
      //need to log error
      return false;
    }

    return true;
  }

  PYBIND11_MODULE(prime_divides, m) {
    m.doc() = "prime divedes plugin"; // optional module docstring
    m.def("write_divides_to_File", &write_divides_to_File);
  }

}