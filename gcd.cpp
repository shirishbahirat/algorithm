#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int gcd(int a, int b)
  {

    while (a != b)
    {
      if (a > b)
        a -= b;
      else
        b -= a;
    }

    return a;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->gcd(2, 33) << endl;

  return 0;
}
