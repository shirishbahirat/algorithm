#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {

    map<char, int> track;

    int length = s.length();

    int left = 0, right = 0;

    int sub_length = 0;

    while (left < length && right < length)
    {

      char el = s[right];

      if (track.find(el) != track.end())
      {
        if (left < track[el] + 1)
          left = track[el] + 1;
      }

      track[el] = right;

      right++;

      if ((right - left) > sub_length)
        sub_length = right - left;
    }

    return sub_length;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string s = "abcabcbb";

  cout << obj->lengthOfLongestSubstring(s) << endl;

  return 0;
}
