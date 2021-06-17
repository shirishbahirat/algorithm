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

    while (start <= end)
    {
      if (people[start] == limit)
      {
        boats++;
        start++;
      }
      else if (people[end] == limit)
      {
        boats++;
        end--;
      }
      else if (people[start] + people[end] <= limit)
      {
        boats++;
        start++;
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
