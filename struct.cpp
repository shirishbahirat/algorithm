#include <iostream>
#include <vector>

using namespace std;

int cmd_handler : 16, header : 16;

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

  return 0;
}
