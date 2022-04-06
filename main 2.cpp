#include "mbox.h"
#include "queue.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

  mbox *mb = new mbox(10, "PSC");

  queue *q = new queue(10, "MB");

  payload *n1 = new payload(1, 1, 1);

  q->insert(&n1);

  payload *n2 = new payload(2, 2, 2);

  q->insert(&n2);

  cout << q->get_size() << endl;

  payload *n = q->remove();

  cout << q->get_size() << endl;

  cout << n->srce_id << " " << n->dest_id << " " << n->mesg_id << endl;

  payload *m = q->remove();

  cout << q->get_size() << endl;

  cout << m->srce_id << " " << m->dest_id << " " << m->mesg_id << endl;

  payload *x1 = new payload(1, 1, 1);

  q->insert(&x1);

  payload *x2 = new payload(2, 2, 2);

  q->insert(&x2);

  payload *x3 = new payload(1, 1, 1);

  q->insert(&x3);

  payload *x4 = new payload(2, 2, 2);

  q->insert(&x4);

  cout << q->get_size() << endl;

  q->reset();

  cout << q->get_size() << endl;

  return 0;
}