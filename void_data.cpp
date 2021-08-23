#include <iostream>
using namespace std;

static const int a15irqmap[] = {
    [VIRT_MMIO] = 16,          /* ...to 16 + NUM_VIRTIO_TRANSPORTS - 1 */
    [VIRT_GIC_V2M] = 48,       /* ...to 48 + NUM_GICV2M_SPIS - 1 */
    [VIRT_PLATFORM_BUS] = 112, /* ...to 112 + PLATFORM_BUS_NUM_IRQS -1 */
    [VIRT_FOO] = 176,
};

struct node
{
  int data;
  node *next;

  node(int d) : data(d), next(NULL) {}
};

int add_node(void *data)
{

  node *n = (node *)data;

  cout << n->data << endl;

  return 0;
}

int main(int argc, char const *argv[])
{

  node *n1 = new node(1000);

  add_node((void *)n1);

  return 0;
}