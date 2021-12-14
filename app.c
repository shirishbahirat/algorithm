#include <stdio.h>

char data[20];

int main(int argc, const char *argv[])
{

  while (1)
  {
    printf(">> ");
    fgets(data, sizeof data, stdin);
    printf("%s\n", data);
  }

  return 0;
}