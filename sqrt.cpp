#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {

    if (x == 0)
      return 0;

    double error = 0.00001;
    long int s = x;

    while ((s - x / s) > error)
    {
      s = (s + x / s) / 2;
    }
    return s;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->mySqrt(2147483647) << endl;

  return 0;
}
