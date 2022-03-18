#include <iostream>

using namespace std;

struct node
{
  int val;
  node *left;
  node *right;
  node(int x) : val(x), left(nullptr), right(nullptr) {}
};

node *insert(node *hd, int val)
{
  if (hd == nullptr)
  {
    hd = new node(val);
    return hd;
  }
  else if ((hd->left == nullptr) && (hd->val < val))
  {
    hd->left = new node(val);
    return hd;
  }
  else if ((hd->right == nullptr) && (hd->val >= val))
  {
    hd->right = new node(val);
    return hd;
  }
  else
  {
    if (hd->left->val < val)
    {
      hd = insert(hd->right, val);
    }
    else
    {
      hd = insert(hd->left, val);
    }
  }

  return hd;
}

int main(int argc, char *argv[])
{

  node *root = nullptr;

  root = insert(root, 5);
  root = insert(root, 10);
  root = insert(root, 4);
  root = insert(root, 6);

  cout << root->val << endl;
  cout << root->left->val << endl;
  cout << root->right->val << endl;

  return 0;
}