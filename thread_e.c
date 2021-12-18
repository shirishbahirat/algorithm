#include <pthread.h>
#include <stdio.h>

int main(int argc, const char **argv)
{

  while (argc)
  {
    printf("%s\n", argv[argc]);
    argc--;
  }

  return 0;
}