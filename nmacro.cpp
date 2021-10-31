#include <iostream>

using namespace std;

#define IN
#define OUT

#define STRUCT_INFO

typedef struct
{
  int fid;
} struct_with_info;

struct_with_info information[] STRUCT_INFO = {{.fid = 123}, {.fid = 456}};

void function_with_types(IN int data, OUT int *addre)
{

  int sum = 10;
  sum += data;

  *addre = sum;

  return;
}

enum etasks
{
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE
};

typedef int (*cpi)(int, int, int);
typedef int (*bpi)(int, int);
typedef int (*api)(int);

struct interface
{
  api in;
  bpi on;
  cpi cn;
};

int ap(int a) { return a; }
int bp(int a, int b) { return a + b; }
int cp(int a, int b, int c) { return a + b + c; }

struct node
{
  int data;
  node *next;
} NODE_V2_CS;

#define ID(version) (NODE_V##version##_CS).data
#define PID(version) (PNODE_V##version##_CS)->data

char ride[] = "\
\"Boot\":\"Disabled\",\
\"values\":[\"once\",\"Disabled\"]";

void convert(char *strng) { cout << strng << endl; }

#define ERROR(info) info

int main(int argc, char const *argv[])
{

  etasks tasks;

  interface intf = {
      .in = ap,
      .on = bp,
      .cn = cp,
  };

  NODE_V2_CS.data = 2;

  node *PNODE_V2_CS = &NODE_V2_CS;

  ID(2) = 4;
  PID(2) = 10;

  cout << NODE_V2_CS.data << endl;

  cout << ride << endl;

  convert(ride);

  string status = ERROR(10) ? "Yes" : "No";

  cout << status << endl;

  for (int i = 0; i <= FIVE; ++i)
  {
    cout << "from enum " << i << endl;
  }

  cout << intf.in(10) << endl;
  cout << intf.on(10, 10) << endl;
  cout << intf.cn(10, 10, 10) << endl;

  int out;
  function_with_types(10, &out);

  cout << "efi like function: " << out << endl;

  cout << "struct with info: " << information[0].fid << endl;
  cout << "struct with info: " << information[1].fid << endl;

  return 0;
}