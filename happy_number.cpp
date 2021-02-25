#include <iostream>
using namespace std;

class Solution
{
public:
  bool isHappy(int n)
  {

    if (n == 1)
      return true;
    else if (n == 4)
      return false;

    int parsed = 0;

    while (n)
    {
      int r = n % 10;
      parsed += (r * r);
      n /= 10;
    }

    return isHappy(parsed);
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  bool results = obj->isHappy(19);

  cout << results << endl;

  return 0;
}
