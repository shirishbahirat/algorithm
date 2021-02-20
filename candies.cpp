#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
  {

    vector<bool> results(candies.size(), false);
    int max = 0;

    for (int i = 0; i < candies.size(); ++i)
    {
      if (candies.at(i) > max)
        max = candies.at(i);
    }

    for (int i = 0; i < candies.size(); ++i)
    {
      if ((candies.at(i) + extraCandies) >= max)
        results.at(i) = true;
    }

    return results;
  }
};

int main(int argc, char const *argv[])
{

  Solution *obj = new Solution();
  vector<int> candies = {5, 1, 3, 3};
  int extraCandies = 2;

  obj->kidsWithCandies(candies, extraCandies);

  return 0;
}
