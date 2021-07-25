#include <iostream>

using namespace std;

#define glue(x, y) x##y

int main(int argc, char const *argv[])
{

  cout << glue(1111, 2222) << endl;

  return 0;
}