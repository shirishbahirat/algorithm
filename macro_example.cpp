#include <iostream>

using namespace std;

struct test_st
{
  int dataa;
  int datab;
  int datac;
};

#define ADDM(a, b, c) a##b##c

#define INIT_STRUCTURE(testx)                                                  \
  {                                                                            \
    .dataa = a, .datab = b, .datac = c                                         \
  }

#define ADDK(a, b, c) test_st testt = {.dataa = a, .datab = b, .datac = c}
#define ADDX(a, b, c) test_st INIT_STRUCTURE(testx, a, b, c)

int main(int argc, char const *argv[])
{

  cout << ADDM(, , 12) << endl;

  ADDK(100, 200, 300);
  ADDX(111, 222, 333);

  cout << testt.dataa << endl;
  cout << testt.datab << endl;
  cout << testt.datac << endl;

  return 0;
}