#pragma once

class queue
{
public:
private:
  struct node
  {
    node *next;
    int srce_id;
    int dest_id;
    void *mesg;
    node(int s, int d) : srce_id(s), dest_id(d), next(nullptr), mesg(nullptr) {}
    node(int s, int d, node *n) : srce_id(s), dest_id(d), next(n), mesg(nullptr)
    {
    }
    node(int s, int d, node *n, void *m)
        : srce_id(s), dest_id(d), next(n), mesg(m)
    {
    }
  };

  node *head;

  int size;
  int limit;
};
