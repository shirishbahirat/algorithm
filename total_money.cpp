#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int totalMoney(int n)
  {

    int week = 0;
    int money = 0;

    while (n)
    {
      if (n > 7)
      {
        n -= 7;
        money += (28 + (7 * week));
        week += 1;
      }
      else
      {
        for (int i = 0; i < n; ++i)
        {
          money += ((i + 1) + week);
        }
        n = 0;
      }
    }

    return money;
  }
};
int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->totalMoney(20) << endl;
  return 0;
}
