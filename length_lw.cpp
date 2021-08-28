#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLastWord(string s)
  {

    int n = s.size();
    int last = 0;
    int first = 0;

    for (int i = 0; i < n; ++i)
    {
      int space = 0;
      if (s[n] == 0x20)
      {
        space++;
      }
      if (space == 0)
      {
        return s.size();
      }
    }

    while (n--)
    {
      if ((last == 0) && (s[n] != 0x20))
      {
        last = n;
        cout << "Last word " << n << endl;
      }

      if ((first == 0) && (s[n] == 0x20) && (last != 0))
      {
        first = n;
        return (last - first);
      }
    }

    return 0;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string s = "";

  cout << obj->lengthOfLastWord(s) << endl;

  return 0;
}
