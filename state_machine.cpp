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

int state_execute(state_t name)
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

  cout << state << endl;

  return 0;
}

int state_change(state_t name)
{
  state = name;
  cout << state << endl;
  return 0;
}

int state_init(state_t name)
{
  if (name == INIT)
  {
    state = INIT;
    cout << state << endl;
    return 0;
  }
  return 1;
}

int state_close(state_t name)
{
  if (name == DONE)
  {
    state = DONE;
    cout << state << endl;
    return 0;
  }
  return 1;
}

int main(int argc, char const *argv[])
{

  state_machine machine = {.execute = state_execute,
                           .change = state_change,
                           .init = state_init,
                           .close = state_close};

  machine.init(INIT);

  return 0;
}