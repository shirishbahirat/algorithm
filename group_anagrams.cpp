#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    vector<vector<string>> ans;
    vector<string> temp = strs;
    map<string, vector<int>> groups;

    for (int i = 0; i < strs.size(); i++)
    {
      sort(temp[i].begin(), temp[i].end());
      groups[temp[i]].push_back(i);
    }

    int idx = 0;

    for (const auto &[key, value] : groups)
    {
      vector<int> grp = groups[key];
      ans.push_back({});

      for (int i = 0; i < grp.size(); i++)
      {
        ans[idx].push_back(strs[grp[i]]);
      }
      idx++;
    }

    return ans;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  obj->groupAnagrams(strs);
  return 0;
}
