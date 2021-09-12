#include <iostream>
#include <vector>

using namespace std;

struct header
{
  unsigned int b1 : 3, : 2, b2 : 6, b3 : 2;
};

struct command
{

  struct
  {
    int node;
    int index;
  };

  struct
  {
  } transition;

  struct
  {
    int next;
    int count;
  };
};

int main(int argc, char const *argv[])
{

  command cmd = {
      .node = 100,
      .index = 1,
      .next = 5,
      .count = 234,
  };

  cout << &cmd.index << endl;
  cout << &cmd.transition << endl;
  cout << &cmd.next << endl;

  header scsi;

  scsi.b1 = 2;
  scsi.b2 = 5;
  scsi.b3 = 3;

  cout << scsi.b1 << endl;
  cout << scsi.b2 << endl;
  cout << scsi.b3 << endl;

  return 0;
}
