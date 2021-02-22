#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
  void swap(vector<int>::iterator x, vector<int>::iterator y)
  {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  void quick_sort(vector<int> &vec, vector<int>::iterator left,
                  vector<int>::iterator right)
  {

    auto size = distance(left, right);
    if (size <= 1)
    {
      return;
    }
    auto pivot = next(right, -1);
    if (size == 2 && *pivot < *left)
    {
      iter_swap(left, pivot);
    }
    auto wall = left;
    auto curr = left;

    while (curr != right)
    {
      if (*curr < *pivot)
      {
        iter_swap(wall, curr);
        wall++;
      }
      curr++;
    }

    swap(pivot, wall);
    quick_sort(vec, left, wall);
    quick_sort(vec, wall + 1, right);
  }

  vector<int> smallerNumbersThanCurrent(vector<int> &nums)
  {

    vector<int> count(nums.size(), 0);

    quick_sort(nums, nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
    {
      set<int> unique;
      for (int j = 0; j < i; j++)
      {
        unique.insert(nums.at(j));
      }

      count.at(i) = unique.size();
    }

    return count;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  vector<int> nums = {8, 1, 2, 2, 3};

  nums = obj->smallerNumbersThanCurrent(nums);

  for (int i = 0; i < nums.size(); ++i)
  {
    cout << nums.at(i) << " ";
  }

  cout << endl;

  return 0;
}
