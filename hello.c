#include <stdio.h>
#include <string.h>

typedef char *DEBUG_MSG;

DEBUG_MSG DATA = "Hello world\n";

#define DEBUG_MSG DATA;

int main(int argc, char **argv)
{

  printf("%s", DEBUG_MSG);

  return 0;
}