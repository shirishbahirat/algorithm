#include <pthread.h>
#include <stdio.h>

int arr[] = {10, 11, 12};

void print_arr(const char **arr)
{
  printf("%s\n", arr[0]);
  return;
}

int main(int argc, const char **argv)
{

  print_arr(argv);

  while (argc > 1)
  {
    argc--;
    printf("%s\n", argv[argc]);
  }

  return 0;
}