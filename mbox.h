#pragma once
#include "queue.h"

class mbox : public queue
{
public:
  mbox(uint32_t l, string n) : queue(l, n) {}
  ~mbox() {}
};