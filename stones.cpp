#include <cstring>
#include <iostream>

using namespace std;

class Solution
{
public:
  int numJewelsInStones(string jewels, string stones)
  {

    int count = 0;
    for (int i = 0; i < jewels.size(); ++i)
    {
      for (int j = 0; j < stones.size(); ++j)
      {
        if (jewels[i] == stones[j])
          count++;
      }
    }

    return count;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  string jewels = "aA";
  string stones = "aAAbbbbb";

  int count = obj->numJewelsInStones(jewels, stones);

  cout << count << endl;

  return 0;
}
