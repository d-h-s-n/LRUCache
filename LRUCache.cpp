#include "LRUCache.h"

LRUCache::LRUCache(int capacity) : _capacity(capacity) {}

int LRUCache::get(int key) {
    auto it = _map.find(key);
    if (it == _map.end()) {
        return -1;
    }

    // Move the accessed item to the front (most recently used)
    _cache.splice(_cache.begin(), _cache, it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value) {
    auto it = _map.find(key);

    if (it != _map.end()) {
        // Update the value and move to front
        it->second->second = value;
        _cache.splice(_cache.begin(), _cache, it->second);
    } else {
        // If cache is full, remove least recently used item
        if (_cache.size() >= _capacity) {
            int lruKey = _cache.back().first;
            _map.erase(lruKey);
            _cache.pop_back();
        }

        // Insert new key-value pair at the front
        _cache.emplace_front(key, value);
        _map[key] = _cache.begin();
    }
}
