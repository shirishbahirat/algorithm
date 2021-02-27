#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isPalindrome(string s)
  {

    string m = "";

    for (int i = 0; i < s.size(); ++i)
    {
      if ((s[i] > 64) && (s[i] < 91))
      {
        m += (char)tolower(s[i]);
      }
      else if ((s[i] > 96) && (s[i] < 123))
      {
        m += s[i];
      }
      else if ((s[i] > 47) && (s[i] < 58))
      {
        m += s[i];
      }
    }

    if ((m.size() == 0) || (m.size() == 1))
      return true;

    if (m.size() < 2)
    {
      return false;
    }

    for (int i = 0, j = (m.size() - 1); i < j; i++, j--)
    {
      if (m[i] != m[j])
        return false;
    }

    return true;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string s = "0P";

  bool status = obj->isPalindrome(s);

  cout << status << endl;
  return 0;
}
