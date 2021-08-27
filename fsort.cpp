#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<int> frequencySort(vector<int> &nums)
  {
    map<int, int> frequency;
    multimap<int, int> ordered;

    for (int i = 0; i < nums.size(); ++i)
    {
      frequency[nums[i]] += 1;
    }

    for (auto const &[key, value] : frequency)
    {
      ordered.insert(pair<int, int>(value, key));
    }

    int idx = 0;
    for (auto const &[key, value] : ordered)
    {
      for (int i = 0; i < key; ++i)
        nums[idx++] = value;
    }

    return nums;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {4, 4, 1, 5, 5, 10};

  nums = obj->frequencySort(nums);

  for (int i = 0; i < nums.size(); ++i)
  {
    cout << nums[i] << " ";
  }

  cout << endl;
  return 0;
}
