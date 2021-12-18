#include <pthread.h>
#include <stdio.h>

int main(int argc, const char **argv)
{

  if (argc > 1)
  {
    printf("%s\n", argv[1]);
  }

  if (argc > 2)
  {
    printf("%s\n", argv[2]);
  }

  return 0;
}