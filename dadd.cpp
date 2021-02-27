#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int nadd(int num)
  {
    if (num <= 9)
      return num;

    int sum = 0;

    while (num)
    {
      int reminder = num % 10;
      sum += reminder;
      num /= 10;
    }

    return nadd(sum);
  }

  int addDigits(int num) { return nadd(num); }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  int result = obj->addDigits(38);

  cout << result << endl;
  return 0;
}
