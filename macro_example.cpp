#include <iostream>

using namespace std;

#define ADD(a, b, c) a##b##c

int main(int argc, char const *argv[])
{

  cout << ADD("a", "b", "c") << endl;

  return 0;
}