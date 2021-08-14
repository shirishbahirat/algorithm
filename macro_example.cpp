#include <iostream>

using namespace std;

struct test_st
{
  int dataa;
  int datab;
  int datac;
};

#define ADDM(a, b, c) a##b##c

#define ADDK(a, b, c) test_st testt = {.dataa = a, .datab = b, .datac = c}

int main(int argc, char const *argv[])
{

  cout << ADDM(, , 12) << endl;

  ADDK(100, 200, 300);

  cout << testt.dataa << endl;
  cout << testt.datab << endl;
  cout << testt.datac << endl;

  return 0;
}