#include <iostream>

using namespace std;

enum state_t
{
  INIT,
  READY,
  BUSY,
  DONE,
  STATES
} state;

struct state_machine
{
  int (*execute)(state_t);
  int (*change)(state_t);
  int (*init)(state_t);
  int (*close)(state_t);
};

int execute_state(state_t name)
{

  switch (name)
  {
  case INIT:
    state = READY;
    break;
  case READY:
    state = BUSY;
    break;
  case BUSY:
    state = DONE;
    break;
  default:
    state = INIT;
  }

  return 0;
}

int state_change(state_t name)
{
  state = name;
  return 0;
}

int main(int argc, char const *argv[]) { return 0; }