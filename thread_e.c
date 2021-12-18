#include <pthread.h>
#include <stdio.h>

int main(int argc, const char **argv)
{

  while (argc > 1)
  {
    argc--;
    printf("%s\n", argv[argc]);
  }

  return 0;
}