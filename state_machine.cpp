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
  state_t (*execute)(state_t);
  state_t (*change)(state_t);
  state_t (*init)(state_t);
  state_t (*close)(state_t);
};

state_t state_execute(state_t name)
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

  cout << "Current state " << state << endl;

  return state;
}

state_t state_change(state_t name)
{
  state = name;
  cout << "Current state " << state << endl;
  return state;
}

state_t state_init(state_t name)
{
  if (name == INIT)
  {
    state = INIT;
    cout << "Current state " << state << endl;
    return state;
  }
  return state;
}

state_t state_close(state_t name)
{
  if (name == DONE)
  {
    state = DONE;
    cout << "Current state " << state << endl;
    return state;
  }
  return state;
}

int main(int argc, char const *argv[])
{

  state_machine machine = {.execute = state_execute,
                           .change = state_change,
                           .init = state_init,
                           .close = state_close};

  cout << "Current state " << state << endl;

  (&machine)->init(INIT);
  (&machine)->execute(READY);
  (&machine)->execute(BUSY);
  (&machine)->change(READY);
  (&machine)->close(DONE);

  return 0;
}