#include <iostream>

using namespace std;

#define COMMAND(NAME) NAME##

int main(int argc, char const *argv[])
{

  cout << COMMAND("shirish") << endl;

  return 0;
}