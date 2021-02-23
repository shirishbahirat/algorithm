#include <iostream>
using namespace std;

class Solution
{
public:
  int subtractProductAndSum(int n)
  {
    if (n == 0)
      return 0;

    int mult = 1;
    int sum = 0;
    while (n)
    {
      int reminder = n % 10;
      sum += reminder;
      mult *= reminder;
      n /= 10;
    }

    return (mult - sum);
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  int out = obj->subtractProductAndSum(234);
  cout << out << endl;
  return 0;
}
