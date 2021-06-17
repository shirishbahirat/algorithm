#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numRescueBoats(vector<int> &people, int limit)
  {

    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size();
    int boats = 0;

    while (start == end)
    {
      if (start == limit)
      {
        boats++;
        start++;
      }
      if (end == limit)
      {
        boats++;
        end--;
      }
    }

    return boats;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
