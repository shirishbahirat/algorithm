#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  char name[] = "John Smith";
  char updated[5] = "";

  char *pname = &name[0];

  string aname = "Alice";

  char xname[] = "Bob";

  for (int i = 0; i < 6; i++)
  {
    updated[i] = name[i];
    cout << updated << " " << pname << " " << aname[i] << endl;
  }

  return 0;
}