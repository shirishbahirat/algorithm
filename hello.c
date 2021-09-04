#include <stdio.h>
#include <string.h>

typedef char *DEBUG_MSG;

DEBUG_MSG DATA = "Hello world\n";

#define DEBUG_MSG "%s",

int main(int argc, char **argv)
{

  printf(DEBUG_MSG "shirish bahirat\n");

  return 0;
}