#include <stdio.h>
#include <string.h>

typedef char *DEBUG_MSG;

DEBUG_MSG DATA = "Hello world\n";

#define DEBUG_MSG
#define NO_MSG

int main(int argc, char **argv)
{

  printf(DEBUG_MSG "test message\n");
  printf(NO_MSG "test no message\n");

  return 0;
}