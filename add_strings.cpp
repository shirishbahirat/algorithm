#include <iostream>
#include <sstream>
using namespace std;

class Solution
{
public:
  string addStrings(string num1, string num2)
  {

    int n1 = 0, n2 = 0;
    int i, j;
    int carry = 0;
    int sum;
    string results = "";

    string str1, str2;

    for (i = (num1.size() - 1), j = (num2.size() - 1); (i >= 0) && (j >= 0);
         --i, --j)
    {

      stringstream s1, s2;
      s1 << num1[i];
      s2 << num2[j];

      str1 = s1.str();
      str2 = s2.str();

      n1 = stoi(str1);
      n2 = stoi(str2);

      sum = n1 + n2 + carry;
      if (sum > 9)
      {
        carry = 1;
        sum %= 10;
      }
      else
      {
        carry = 0;
      }

      results = to_string(sum) + results;
    }

    while (j >= 0)
    {
      stringstream s2;
      s2 << num2[j];
      str2 = s2.str();
      n2 = stoi(str2);

      sum = n2 + carry;

      if (sum > 9)
      {
        carry = 1;
        sum %= 10;
      }
      else
      {
        carry = 0;
      }

      results = to_string(sum) + results;
      --j;
    }

    while (i >= 0)
    {
      stringstream s1;
      s1 << num1[i];
      str1 = s1.str();
      n1 = stoi(str1);

      sum = n1 + carry;

      if (sum > 9)
      {
        carry = 1;
        sum %= 10;
      }
      else
      {
        carry = 0;
      }

      results = to_string(sum) + results;
      --i;
    }

    if (carry)
    {
      results = to_string(carry) + results;
    }

    return results;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  string results = obj->addStrings("408", "5");

  cout << results << endl;
  return 0;
}
