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
  printf("%d\n", **arr);
  (*arr)++;
  printf("%d\n", **arr);
  (*arr)++;
  printf("%d\n", **arr);
  return;
}

void foo(int **array) { printf("%d\n", **array); }
void fox(int *array[]) { printf("%d\n", **array); }

int main(int argc, const char **argv)
{

  print_arr(argv);
  print_arn(&parr);

  while (argc > 1)
  {
    argc--;
    printf("%s\n", argv[argc]);
  }
  foo(&parr);
  fox(&parr);

  return 0;
}