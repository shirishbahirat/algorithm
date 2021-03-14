#include <iostream>
using namespace std;

void fun(int n)
{
  cout << n << endl;
  if (n > 0)
  {
    fun(n - 1);
  }
}
int main()
{
  int x = 5;
  fun(x);
}