// multiply_library.cpp : Defines the exported functions for the DLL.
//

#include "framework.h"
#include "multiply_library.h"
#include "pch.h"
#include "Simple_Divides.h"
   
std::vector<size_t> get_divides(const std::vector<size_t> items, const std::string &output_file_name)
{
  struct data {
    size_t number=0;
    std::vector<size_t> divides;
  };

  if (output_file_name.empty() || items.empty())
  {
    return {};
  }

  Simple_Divides prime;
  std::vector<data> result;  

  for (size_t i=0; i<items.size(); ++i)
  {
    //in this place we can parallel our calculates
    result.push_back({ items[i], prime.prime_div(items[i]) }); 
  }


  std::ofstream out;
  try {
    out.open(output_file_name);

    for (auto& data : result)
    {
      out << data.number <<" = 1";
      for (auto& d : data.divides)
      {
        out << " * " << d;
      }
      out << endl;
    }
  }
  catch (std::exception& ex)
  {
    //log error
  }
  
  //create file and write results
  return {};

}
 
PYBIND11_MODULE(multiply_library, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring
  m.def("get_divides",&get_divides);
  
}

