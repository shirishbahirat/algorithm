#include <iostream>

using namespace std;

struct node
{
  int manager[2];
  int idx;
  int data;
};

int main(int argc, char const *argv[])
{

  node nd = {
      .data = 1000,
      .manager = {4, 5},
      .idx = 10,
  };

  cout << nd.manager[0] << " " << nd.manager[1] << endl;
  cout << nd.idx << " " << nd.data << endl;

  return 0;
}