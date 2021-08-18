#include <iostream>

using namespace std;

struct test_st
{
  int dataa;
  int datab;
  int datac;
};

#define ADDM(a, b, c) a##b##c

#define INIT_STRUCTURE(test_st, a, b, c)                                       \
  test_st testx { .dataa = a, .datab = b, .datac = c }

#define ADDK(a, b, c) test_st testt = {.dataa = a, .datab = b, .datac = c}
#define ADDX(a, b, c) INIT_STRUCTURE(test_st, a, b, c)

int main(int argc, char const *argv[])
{

  cout << ADDM(, , 12) << endl;

  ADDK(1000, 2000, 3000);
  ADDX(1111, 2222, 3333);

  cout << testt.dataa << endl;
  cout << testt.datab << endl;
  cout << testt.datac << endl;

  cout << testx.dataa << endl;
  cout << testx.datab << endl;
  cout << testx.datac << endl;

  return 0;
}