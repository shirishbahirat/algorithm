#include <stdio.h>

char data[20];

int vect[] = {10, 3, 5, 3, 9, 11, 6, 8, 0xFFFF};

void swap(int *v, int a, int b)
{
  if (a != b)
  {
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
  }
}

void print_vect(int v[], int len)
{
  int i = 0;
  for (i = 0; i < len; ++i)
  {
    printf("%d ", v[i]);
  }
}

int partition(int low, int high)
{
  int pivot = vect[0];

  int idx = low;
  int idy = high;

  return 0;
}

int main(int argc, const char *argv[])
{

  while (1)
  {
    printf(">> ");
    fgets(data, sizeof data, stdin);
  }

  return 0;
}