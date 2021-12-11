
#include <stdio.h>

#define DEBUG(...)                                                             \
  do                                                                           \
  {                                                                            \
    printf(__VA_ARGS__);                                                       \
  } while (0)

int main(int argc, char const *argv[])
{

  DEBUG("CAM\n"
        "B\n"
        "CFGDC\n");

  DEBUG("12\n");

  return 0;
}