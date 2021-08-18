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

  fp = fopen("test_textfile.txt", "a");
  char str[20] = "Hello Again.";
  if (fp)
  {
    putc('\n', fp);
    for (int i = 0; i < strlen(str); i++)
      putc(str[i], fp);
  }
  fclose(fp);

  return 0;
}