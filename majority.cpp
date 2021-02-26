#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {

    map<int, int> count;
    int max = 0;
    int number = -1;

    for (int i = 0; i < nums.size(); ++i)
    {
      count[nums.at(i)] += 1;
      if (count[nums.at(i)] > max)
      {
        max = count[nums.at(i)];
        number = nums.at(i);
      }
    }

    return number;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> nums = {3, 1, 3};

  int majority = obj->majorityElement(nums);

  cout << majority << endl;
  return 0;
}
