#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<string> fizzBuzz(int n)
  {
    vector<string> soln;

    for (int i = 0, j = 1; i < n; ++i, ++j)
    {
      if (!(j % 3) && (j % 5))
      {
        soln.push_back("Fizz");
      }
      else if (!(j % 5) && (j % 3))
      {
        soln.push_back("Buzz");
      }
      else if (!(j % 5) && !(j % 3))
      {
        soln.push_back("FizzBuzz");
      }
      else
      {
        soln.push_back(to_string(j));
      }
    }

    return soln;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  vector<string> output = obj->fizzBuzz(15);

  for (int i = 0; i < output.size(); ++i)
  {
    cout << output[i] << endl;
  }
  return 0;
}
