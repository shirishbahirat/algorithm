#pragma once
#include <cstdint>

using namespace std;

struct payload
{
  payload *next;
  uint32_t srce_id;
  uint32_t dest_id;
  uint32_t mesg_id;
  void *mesg;
  payload(uint32_t s, uint32_t d, uint32_t i)
      : srce_id(s), dest_id(d), mesg_id(i), next(nullptr), mesg(nullptr)
  {
  }
  payload(uint32_t s, uint32_t d, uint32_t i, payload *n)
      : srce_id(s), dest_id(d), mesg_id(i), next(n), mesg(nullptr)
  {
  }
  payload(uint32_t s, uint32_t d, uint32_t i, payload *n, void *m)
      : srce_id(s), dest_id(d), mesg_id(i), next(n), mesg(m)
  {
  }
};
