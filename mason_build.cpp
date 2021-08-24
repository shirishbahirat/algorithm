#include <iostream>

using namespace std;

int arr[] = {[10] = 10, [3] = 3}

int main(int argc, const char *argv[])
{
  cout << "Hello there" << endl;

  for (int i = 0; i < 11; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}