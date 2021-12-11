#include <iostream>

#define MMU_DEBUG(...)                                                         \
  do                                                                           \
  {                                                                            \
    printf(__VA_ARGS__);                                                       \
  } while (0)

int main(int argc, char const *argv[]) { return 0; }