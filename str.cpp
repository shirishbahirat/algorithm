#include <iostream>

using namespace std;

struct node
{
  int manager[2];
  int idx;
  int data;
  int count;
};

int main(int argc, char const *argv[])
{

  node nd = {
      .data = 2000,
      .manager = {40, 50},
      .idx = 1111,
      .count = 10,
  };

  cout << nd.manager[0] << " " << nd.manager[1] << endl;
  cout << nd.idx << " " << nd.data << endl;
  cout << nd.count << endl;

  return 0;
}