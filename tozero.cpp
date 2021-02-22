#include <iostream>
using namespace std;

class Solution
{
public:
  int numberOfSteps(int num)
  {

    bitset<64> bs(num);

    cout << bs << endl;

    return 0;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  obj->numberOfSteps(123);
  return 0;
}
