#include <iostream>
#include "LRUCache.h"

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout << "Get 1: " << cache.get(1) << std::endl;  // Should print 1

    cache.put(3, 3);  // Evicts key 2
    std::cout << "Get 2: " << cache.get(2) << std::endl;  // Should print -1

    cache.put(4, 4);  // Evicts key 1
    std::cout << "Get 1: " << cache.get(1) << std::endl;  // Should print -1
    std::cout << "Get 3: " << cache.get(3) << std::endl;  // Should print 3
    std::cout << "Get 4: " << cache.get(4) << std::endl;  // Should print 4

    return 0;
}
