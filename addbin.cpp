#include <iostream>
using namespace std;

class Solution
{
public:
  string addBinary(string a, string b)
  {

    int as = a.size();
    int bs = b.size();
    int carry = 0;
    string results = "";

    --as;
    --bs;

    cout << as << " " << bs << endl;

    while ((as >= 0) && (bs >= 0))
    {

      if (((a[as] == '1') && (b[bs] == '1')) && (carry == 0))
      {
        results = "0" + results;
        carry = 1;
      }
      else if (((a[as] == '0') && (b[bs] == '0')) && (carry == 1))
      {
        results = "1" + results;
        carry = 0;
      }
      else if (((a[as] == '1') && (b[bs] == '0')) && (carry == 1))
      {
        results = "0" + results;
        carry = 1;
      }
      else if (((a[as] == '0') && (b[bs] == '1')) && (carry == 1))
      {
        results = "0" + results;
        carry = 1;
      }
      else if (((a[as] == '1') && (b[bs] == '0')) && (carry == 0))
      {
        results = "1" + results;
        carry = 0;
      }
      else if (((a[as] == '0') && (b[bs] == '1')) && (carry == 0))
      {
        results = "1" + results;
        carry = 0;
      }
      else if (((a[as] == '0') && (b[bs] == '0')) && (carry == 0))
      {
        results = "0" + results;
        carry = 0;
      }
      else if (((a[as] == '1') && (b[bs] == '1')) && (carry == 1))
      {
        results = "1" + results;
        carry = 1;
      }

      --as;
      --bs;
    }

    cout << results << endl;

    while (as >= 0)
    {
      if ((a[as] == '1') && (carry == 1))
      {
        results = "0" + results;
        carry = 1;
      }
      else if ((a[as] == '0') && (carry == 1))
      {
        results = "1" + results;
        carry = 0;
      }
      else if ((a[as] == '1') && (carry == 0))
      {
        results = "1" + results;
        carry = 0;
      }
      else if ((a[as] == '0') && (carry == 0))
      {
        results = "0" + results;
        carry = 0;
      }
      as--;
    }

    while (bs >= 0)
    {
      if ((b[bs] == '1') && (carry == 1))
      {
        results = "0" + results;
        carry = 1;
      }
      else if ((b[bs] == '0') && (carry == 1))
      {
        results = "1" + results;
        carry = 0;
      }
      else if ((b[bs] == '1') && (carry == 0))
      {
        results = "1" + results;
        carry = 0;
      }
      else if ((b[bs] == '0') && (carry == 0))
      {
        results = "0" + results;
        carry = 0;
      }
      bs--;
    }

    if (carry)
    {
      results = "1" + results;
      carry = 0;
    }

    return results;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  string results = obj->addBinary("100", "110010");
  cout << results << endl;
  return 0;
}
