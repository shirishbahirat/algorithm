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
  printf("\n");
}

int partition(int low, int high)
{
  int pivot = vect[0];

  int idx = low;
  int idy = high;

  while ((vect[idx] <= pivot) && (idx < high))
  {
    idx++;
  }

  while ((vect[idy] > pivot) && (idy > low))
  {
    idy--;
  }

  if (idx < idy)
  {
    swap(vect, idx, idy);
  }

  return 0;
}

int main(int argc, const char *argv[])
{

  print_vect(vect, 8);

  while (1)
  {
    printf(">> ");
    fgets(data, sizeof data, stdin);
  }

  return 0;
}