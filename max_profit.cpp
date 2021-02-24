#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int max = 0;
    int min = 0xEFFFFFF;
    int max_idx = 0;
    int min_idx = 0;
    int profit = 0;

    for (int i = 0; i < prices.size(); ++i)
    {
      if (prices.at(i) > max)
      {
        max = prices.at(i);
        max_idx = i;
      }

      if (prices.at(i) < min)
      {
        min = prices.at(i);
        min_idx = i;
      }
    }

    cout << max << " " << min << endl;

    if (max_idx < min_idx)
    {
      profit = max - min;
    }

    return profit;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  int profit = obj->maxProfit(prices);

  cout << profit << endl;
  return 0;
}
