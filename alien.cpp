#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isAlienSorted(vector<string> &words, string order) { return true; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution(); //
  string order = "bb";
  vector<string> words = {"aa", "bb"};
  obj->isAlienSorted(words, order);
  return 0;
}
