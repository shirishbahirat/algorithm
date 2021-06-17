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
    int end = people.size() - 1;
    int boats = 0;

    while (start < end)
    {
      if (start == end)
      {
        boats++;
        break;
      }
      if (people[start] + people[end] <= limit)
      {
        start++;
      }

      boats++;
      end--;
    }

    return boats;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<int> people = {1, 2};
  int limit = 3;

  cout << obj->numRescueBoats(people, limit) << endl;

  return 0;
}
