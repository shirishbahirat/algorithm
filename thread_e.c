#include <pthread.h>
#include <stdio.h>

int arr[] = {10, 11, 12};

int *parr = arr;

void print_arr(const char **arr)
{
  printf("%s\n", arr[0]);
  return;
}

void print_arn(int **arr)
{
  printf("%d\n", *arr[0]);
  printf("%d\n", *arr[1]);
  printf("%d\n", *arr[2]);
  return;
}

int main(int argc, const char **argv)
{

  print_arr(argv);
  print_arn(&parr);

  while (argc > 1)
  {
    argc--;
    printf("%s\n", argv[argc]);
  }

  return 0;
}