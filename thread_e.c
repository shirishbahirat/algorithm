#include <pthread.h>
#include <stdio.h>

int main(int argc, const char **argv)
{

  while (argc)
  {
    argc--;
    printf("%s\n", argv[argc]);
  }

  return 0;
}