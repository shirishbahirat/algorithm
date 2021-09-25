#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {

    vector<vector<int>> temp;

    for (int idx = 0; idx < (intervals.size() - 1); ++idx)
    {
      if ((intervals[idx][1]) > (intervals[idx + 1][0]))
      {
        intervals[idx + 1][0] = intervals[idx][1];
      }

      if ((intervals[idx + 1][0]) > (intervals[idx + 1][1]))
      {
        intervals[idx + 1][1] = intervals[idx + 1][0];
      }
    }

    for (int idx = 0; idx < (intervals.size() - 1); ++idx)
    {
      if ((intervals[idx][1]) > (intervals[idx + 1][1]))
      {
        intervals[idx + 1][1] = intervals[idx][1];
      }
    }

    for (int i = 0; i < intervals.size(); ++i)
    {
      cout << intervals[i][0] << " " << intervals[i][1] << endl;
    }

    return temp;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<vector<int>> interval = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

  obj->merge(interval);

  return 0;
}
