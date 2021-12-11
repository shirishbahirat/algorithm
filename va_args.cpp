#include <cstdio>
#include <iostream>
#include <stdio.h>

using namespace std;

#define DEBUG(...)                                                             \
  do                                                                           \
  {                                                                            \
    cout << __VA_ARGS__ << endl;                                               \
  } while (0)

int main(int argc, char const *argv[])
{

  DEBUG(3, 2, 4, 5);

  return 0;
}