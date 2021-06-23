#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    int val = 0;
    int nodes = 0;

    ListNode *main_pointer = head;
    ListNode *following_pointer = head;

    while (main_pointer->next)
    {
      val++;
      nodes++;

      main_pointer = main_pointer->next;

      if (val > n)
      {
        following_pointer = following_pointer->next;
      }
    }

    if (nodes == 0 and n == 1)
      return nullptr;

    if (val)
    {
      ListNode *temp = following_pointer->next;

      following_pointer->next = following_pointer->next->next;

      delete temp;
    }

    return head;
  }
};

int main(int argc, char const *argv[])
{
  Solution *obj = new Solution();
  return 0;
}
