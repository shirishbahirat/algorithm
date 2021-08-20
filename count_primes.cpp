#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
  int countPrimes(int n)
  {

    if (n < 2)
      return 0;

    vector<bool> primes(n, true);

    primes[0] = false;
    primes[1] = false;

    int idx = 2;
    int idy = 2;
    int ans = 0;

    while ((idx * idx) < n)
    {
      while ((idx * idy) < n)
      {
        int num = idx * idy;
        primes[num] = false;
        idy++;
      }
      idx++;
      idy = idx;
    }

    for (int i = 0; i < n; ++i)
    {
      if (primes[i] == true)
        ans++;
    }

    return ans;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();

  cout << obj->countPrimes(25) << endl;
  return 0;
}
