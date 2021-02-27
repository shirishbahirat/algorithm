#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool validPalindrome(string s)
  {

    int i = 0;
    int j = (s.size() - 1);
    int count1 = 0;
    int count2 = 0;

    while (i < j)
    {
      if (s[i] == s[j])
      {
        ++i;
        --j;
      }
      else
      {
        --j;
        count1++;
      }
    }

    i = 0;
    j = (s.size() - 1);
    while (i < j)
    {
      if (s[i] == s[j])
      {
        ++i;
        --j;
      }
      else
      {
        ++i;
        count2++;
      }
    }

    if ((count1 < 2) || (count1 < 1))
      return true;
    else
      return false;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  string s = "cbbcc";
  bool out = obj->validPalindrome(s);

  cout << out << endl;
  return 0;
}
