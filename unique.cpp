#include <iostream>
#include <map>
using namespace std;

class Solution
{
public:
  int firstUniqChar(string s)
  {

    map<char, int> count;
    int cnt = -1;

    for (int i = 0; i < s.size(); ++i)
    {
      count[s[i]] += 1;
    }

    for (int i = 0; i < s.size(); ++i)
    {
      if (count[s[i]] == 1)
      {
        cnt = i;
        break;
      }
    }

    return cnt;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  int result = obj->firstUniqChar("abbcced");

  cout << result << endl;

  return 0;
}
