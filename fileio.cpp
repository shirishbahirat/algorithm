#include <cstdio>
#include <iostream>

int main(int argc, char const *argv[])
{

  FILE *fid = fopen("test_textfile.txt", "r");

  double trainsample;
  if (fid)
  {
    while (!feof(fid))
    {
      fscanf(fid, "%lf", &trainsample);
      printf("%lf\n", trainsample);
    }
  }

  return 0;
}