#include <iostream>
#include <vector>

using namespace std;

void (*f)(int);

void test(int c) { cout << c << endl; }

class Solution
{
public:
  Solution() {}

  static void (*f)(int);

  int pivotIndex(vector<int> &nums) { return 0; }

  static void test(int c) { cout << c + 100 << endl; }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  f = test;

  f(101);
  f(111);
  f(222);

  f = obj->test;

  f(100);
  f(111);
  f(222);

  return 0;
}
