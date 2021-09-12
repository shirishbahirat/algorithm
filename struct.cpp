#include <iostream>
#include <vector>

using namespace std;

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

int main(int argc, char const *argv[]) { return 0; }
