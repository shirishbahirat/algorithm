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
    }
    else
    {
      if (lru.size() > size)
      {
        return;
      }
      else
      {
        lru.push_back(key);
        cache[key] = value;
      }
    }

    for (int i = 0; i < lru.size(); ++i)
    {
      cout << lru[i] << " ";
    }
    cout << endl;
  }

private:
  int size;
  map<int, int> cache;
  vector<int> lru;
};

int main(int argc, char const *argv[])
{
  LRUCache *obj = new LRUCache(2);
  obj->get(2);
  obj->put(1, 1);
  obj->put(2, 2);
  cout << obj->get(1) << endl;
  obj->put(3, 3);
  cout << obj->get(2) << endl;
  obj->put(4, 4);
  cout << obj->get(1) << endl;
  cout << obj->get(3) << endl;
  cout << obj->get(4) << endl;

  return 0;
}
