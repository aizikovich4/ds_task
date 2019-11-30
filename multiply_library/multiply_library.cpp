#include "stdafx.h"
#include "Simple_Digits.h"



int main()
{
  
  Simple_Digits_Singleton *prime_singleton;
  
/*  vector<size_t> test{ 1,2,3,4,5,6,7,8,99,50,47,48,83,404,83,83 };
    
  for (auto t : test)
  {
      cout <<t<<" is simple: "<< prime_singleton->getInstance().is_simple(t) << endl;
  }
  */
  
  size_t n=5004;
  prime_singleton->getInstance().prime_div(n);
 

  return 0;
}
