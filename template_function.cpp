#include <iostream>
using namespace std;

template <class t> t maxim(t a, t b) { return a > b ? a : b; }
int main()
{
  cout << maxim(16, 14) << endl;
  cout << maxim(2.4, 1.4) << endl;
  cout << maxim(2.3f, 4.6f) << endl;
  return 0;
}