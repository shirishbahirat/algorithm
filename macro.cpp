#include <iostream>

using namespace std;

#define GLUER(x, y, z) x##y##z

int main(int argc, char const *argv[])
{

  cout << GLUER("shirish", "d", "bahirat") << endl;

  return 0;
}