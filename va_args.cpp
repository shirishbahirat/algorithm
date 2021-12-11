#include <iostream>

#define DEBUG(...)                                                             \
  do                                                                           \
  {                                                                            \
    printf(__VA_ARGS__);                                                       \
  } while (0)

int main(int argc, char const *argv[])
{

  DEBUG(3, 2, 4, 5)

  return 0;
}