#include <iostream>
using namespace std;

class Solution
{
public:
  int numberOfSteps(int num)
  {

    bitset<64> bs(num);
    int msb = 0;

    asm("bsrl %1, %0" : "=r"(msb) : "r"(num));

    for (int i = 0; i <= msb; ++i)
    {
      if (bs[i])
        msb++;
    }
    return msb;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  int msb = obj->numberOfSteps(0);
  cout << msb << endl;
  return 0;
}
