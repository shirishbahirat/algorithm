#include <iostream>
#include <map>
#include <vector>

using namespace std;

class LRUCache
{
public:
  LRUCache(int capacity) : size(capacity) {}

  int get(int key)
  {

    int idx = -1;

    for (int i = 0; i < lru.size(); ++i)
    {
      if (lru[i] == key)
        idx = i;
    }

    if (idx >= 0)
    {
      lru.erase(lru.begin() + idx);
    }
    else
    {
      return -1;
    }

    lru.push_back(key);

    return cache[key];
  }

  void put(int key, int value)
  {

    int idx = -1;

    for (int i = 0; i < lru.size(); ++i)
    {
      if (lru[i] == key)
        idx = i;
    }

    if (idx >= 0)
    {
      cache[key] = value;
      lru.erase(lru.begin() + idx);
      lru.push_back(key);
    }
    else
    {
      if (lru.size() >= size)
      {
        lru.erase(lru.begin());
      }

      lru.push_back(key);
      cache[key] = value;
    }
  }

private:
  int size;
  map<int, int> cache;
  vector<int> lru;
};

int main(int argc, char const *argv[])
{
  LRUCache *obj = new LRUCache(2);
  obj->put(2, 1);
  obj->put(1, 2);
  obj->put(2, 3);
  obj->put(4, 1);
  cout << obj->get(1) << endl;
  cout << obj->get(2) << endl;

  return 0;
}
