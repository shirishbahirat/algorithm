#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  char name[] = "John Smith";
  char updated[5] = "";

  char *pname = &name[0];

  string *aname = "Alice";

  for (int i = 0; i < 4; i++)
  {
    updated[i] = name[i];
    cout << updated << " " << pname << endl;
  }

  return 0;
}