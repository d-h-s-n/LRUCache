#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int capacity);  // public class
    int get(int key);
    void put(int key, int value);

private:                // private class oops concept
    int _capacity;
    std::list<std::pair<int, int>> _cache;  // these are most recently used
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> _map;
};

#endif 
