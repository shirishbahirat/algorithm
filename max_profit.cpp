#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {

    int minprice = 0x7FFFFFFF;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
      if (prices[i] < minprice)
        minprice = prices[i];
      else if (prices[i] - minprice > maxprofit)
        maxprofit = prices[i] - minprice;
    }

    return maxprofit;
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
