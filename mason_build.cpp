#include <iostream>

using namespace std;

int arr[] = {[9] = 10, [3] = 3};

int main(int argc, const char *argv[])
{
  cout << "Hello test" << endl;

  for (int i = 0; i < 10; i++)
  {
    cout << arr[i] << "   ";
  }
  cout << endl;

  return 0;
}