#include <cstdio>
#include <iostream>

int main(int argc, char const *argv[])
{

  int c;
  FILE *fp;
  fp = fopen("test_textfile.txt", "r");
  if (fp)
  {
    while ((c = getc(fp)) != EOF)
      putchar(c);
    fclose(fp);
  }

  return 0;
}