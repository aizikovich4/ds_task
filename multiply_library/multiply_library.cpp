#include "stdafx.h"
#include "Simple_Digits.h"

using namespace std; //TODO delete on release




int main()
{
  
  Simple_Digits simple(50);

  vector<size_t> test{ 1,2,3,4,5,6,7,8,99,50,47,48,83,404,83,83 };
    
  for (auto t : test)
  {
      cout <<t<<" is simle: "<< simple.is_simple(t) << endl;
  }

  /*
  int n, div = 2;
  cout << "N = ";
  cin >> n;
  cout << n << " = 1";
  while (n > 1)
  {
    while (n % div == 0)
    {
      cout << " * " << div;
      n = n / div;
    }
    div++;
  }
  cin.get(); cin.get();*/
  return 0;
}
