#include <iostream>

using namespace std;

#define glue(x, y) x##y

int main(int argc, char const *argv[])
{

  cout << glue(1 -, 200) << endl;

  return 0;
}