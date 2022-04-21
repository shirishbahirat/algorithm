#pragma once

#include "tlm.h"

class ncore_interconnect_rx;
class ncore_interconnect_tx;

class ncore_interconnect_tx
{
public:
  virtual void mb_isr(payload *req) = 0;

  virtual void ready() = 0;

  virtual void connect(ncore_interconnect_rx *inx) = 0;

  virtual ~ncore_interconnect_tx() {}
};

class ncore_interconnect_rx
{
public:
  virtual void connect(ncore_interconnect_tx *tnx) = 0;

  virtual ~ncore_interconnect_rx() {}
};