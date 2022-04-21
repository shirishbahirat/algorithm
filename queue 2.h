#pragma once
#include "types.h"
#include <string>

using namespace std;

class queue
{
public:
  queue(uint32_t l, string n) : size(0), limit(l), name(n), head(nullptr) {}
  ~queue() {}

  bool insert(payload **n)
  {

    if (size >= limit)
      return false;

    size++;

    if (head == nullptr)
    {
      head = *n;
      return true;
    }

    payload *temp = head;

    while (head->next != nullptr)
    {
      head = head->next;
    }

    head->next = *n;

    head = temp;

    return true;
  }

  payload *remove()
  {
    if (head == nullptr)
      return nullptr;

    payload *temp = head;

    head = head->next;

    size--;

    return temp;
  }

  void reset()
  {
    if (head == nullptr)
      return;

    while (head)
    {
      payload *temp = head;
      head = head->next;
      delete temp;
      size--;
    }
  }

  uint32_t get_size() { return size; }

  uint32_t get_limit() { return limit; }

  void set_limit(uint32_t l) { limit = l; }

  string get_name() { return name; }

private:
  uint32_t size;
  uint32_t limit;
  string name;

  payload *head;
};
