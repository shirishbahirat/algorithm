#include <pthread.h>
#include <stdio.h>

int main(int argc, const char **argv)
{

  if (argc > 1)
  {
    printf("%s\n", argv[1]);
  }

  return 0;
}