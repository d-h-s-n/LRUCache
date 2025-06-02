#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    int _capacity;
    std::list<std::pair<int, int>> _cache;  // Front: most recently used
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> _map;
};

#endif // LRUCACHE_H
