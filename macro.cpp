#include <iostream>

using namespace std;

#define glue(x, y) x##_y

int main(int argc, char const *argv[])
{

  cout << glue(1100, 200) << endl;

  return 0;
}