#include <iostream>

using namespace std;

int arr[] = {[10] = 10};

int main(int argc, const char *argv[])
{
  cout << "Hello there" << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << " " << endl;
  }
  cout << endl;

  return 0;
}