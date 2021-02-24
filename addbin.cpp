#include <iostream>
using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {

    int as = a.size();
    int bs = b.size();

    return "0";
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  string results = obj->addBinary("11", "1");
  return 0;
}
