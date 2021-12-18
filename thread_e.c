#include <pthread.h>
#include <stdio.h>

int arr[] = {10, 11, 12};

int *prr = arr;
int **pr = &prr;

int main(int argc, const char **argv)
{

  while (argc > 1)
  {
    argc--;
    printf("%s\n", argv[argc]);
  }

  printf("%s\n", pr[0]);

  return 0;
}