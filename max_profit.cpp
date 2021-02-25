#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int profit = 0;
    for (int i = 0; i < prices.size(); ++i)
    {
      for (int j = i; j < prices.size(); ++j)
      {
        if (prices.at(i) < prices.at(j))
        {
          int temp = (prices.at(j) - prices.at(i));
          if (temp > profit)
          {
            profit = temp;
          }
        }
      }
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
