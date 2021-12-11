
#include <stdio.h>

#define DEBUG(...)                                                             \
  do                                                                           \
  {                                                                            \
    printf(__VA_ARGS__);                                                       \
  } while (0)

int main(int argc, char const *argv[])
{

  DEBUG("C A M\n"
        "B\n");

  return 0;
}