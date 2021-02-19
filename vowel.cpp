#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string removeVowels(string s)
  {

    string tmp;

    for (int i = 0; i < s.size(); ++i)
    {
      if (!(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u'))
      {
        tmp += s[i];
      }
    }

    return tmp;
  }
};

int main(int argc, char const *argv[])
{

  Solution *soln = new Solution();

  string s = "leetcodeisacommunityforcoders";

  s = soln->removeVowels(s);

  cout << s << endl;

  return 0;
}