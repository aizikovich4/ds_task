#include "stdafx.h"
#include "Simple_Digits.h"

using namespace std; //TODO delete on release




int main()
{
  
  Simple_Digits_Singleton *prime_singleton;
  
  vector<size_t> test{ 1,2,3,4,5,6,7,8,99,50,47,48,83,404,83,83 };
    
  for (auto t : test)
  {
      cout <<t<<" is simple: "<< prime_singleton->getInstance().is_simple(t) << endl;
  }

  
  size_t n=5047893, div = 2;
  try
  {


    while (n > 1)
    {
      while (n % div == 0)
      {
        cout << " * " << div;
        n = n / div;
      }
      div = prime_singleton->getInstance().next_simple(div);
    }
  }
  catch (std::exception& ex)
  {
    cout << ex.what() << endl;
  }
  

  return 0;
}
