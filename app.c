#include <stdio.h>

char data[20];

int vect[] = {4, 10, 5, 3, 9, 11, 6, 8, 0xFFFF};

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

  while (idx < idy)
  {
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
  }

  swap(vect, low, idy);

  return idy;
}

void quick_sort(int low, int high)
{
  while (low < high)
  {
    int mid = partition(low, high);
    quick_sort(low, mid);
    quick_sort(mid + 1, high);
  }
}

int main(int argc, const char *argv[])
{

  quick_sort(0, 8);
  print_vect(vect, 8);

  /*
    while (1)
    {
      printf(">> ");
      fgets(data, sizeof data, stdin);
    }
    */

  return 0;
}