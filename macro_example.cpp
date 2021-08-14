#include <iostream>

using namespace std;

#define ADDM(a, b, c) a##b##c

int main(int argc, char const *argv[])
{

  cout << ADDM("a", "b", "c") << endl;

  return 0;
}