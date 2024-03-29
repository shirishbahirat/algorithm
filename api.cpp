#include <iostream>
using namespace std;

#define TEST_DEFINE 1

int (*macro)(int);

typedef int (*macro_t)(int);

#define FUNCTION_MACRO(d) macro(d)

int recasted_number = 1000;

int macr(int data)
{
  cout << "mac " << data << endl;
  return 0;
}

#define TEST_FUNCTION(data)                                                    \
  do                                                                           \
  {                                                                            \
    cout << "data from test function " << data << endl;                        \
  } while (0)

enum
{
  DATA_TYPE_NAME = 0x10101
};

typedef int (*funct)(int);

struct vf
{
  union
  {
    struct
    {
      int data;
    } pp;
    struct
    {
      int ndata;
    };
  };
};

struct api
{
  funct send[10];
};

int sent(int data)
{
  cout << "from api " << data << endl;
  return 0;
}

int main(int argc, char const *argv[])
{

  api vm = {.send[0] = &sent};
  vf nc;

  nc.pp.data = 21000;
  vm.send[0](100);
  cout << nc.pp.data << " " << nc.ndata << endl;
  nc.ndata = 3100;
  cout << nc.pp.data << " " << nc.ndata << endl;

  if (0)
  {
    goto passed;
  }

  if (!!TEST_DEFINE)
  {
    cout << "test variable" << endl;
  }

passed:
  cout << "skipped test variable " << DATA_TYPE_NAME << endl;

  TEST_FUNCTION(111111);

  macro = macr;

  FUNCTION_MACRO(333);

  macro_t macfc = &macr;

  macfc(444);

  cout << "recasted " << (uint32_t)(int long)recasted_number << endl;

  return 0;
}