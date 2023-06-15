#include<bits/stdc++.h>
using namespace std;
/*LRU Cache implemented using list and unordered map data structures
Unordered map - responsible for storing the key-value pairs
list - responsible for allowing us to access the front and last items
for this cache, the item at front of the list is the Least Recently Used item,
and the item at the last (back) of the list is the most recently used item
*/
class LRUCache {
public:
unordered_map<int,int> cache_map; //stores the key-value pairs
list<int> cache; //the cache is basically implemented with list data structure
int cap; //the capacity of the LRU Cache, given as input by the user

LRUCache(int capacity) {
    cap = capacity;
    cache.clear(); //cache initially cleared
    cache_map.clear(); //map initially cleared
}

int get(int key) {
    if(cache_map.find(key) == cache_map.end()) //key is not present in the cache
    {
        return -1;
    }
    //key is present in the cache
    cache.remove(key); //key is removed from it's current position
    cache.push_back(key); // key is pushed to the last of the cache, as it has been most most recently used
    return cache_map[key]; //returning value corresponding to the key
    }

void put(int key, int value) {
    if(cache_map.find(key) == cache_map.end()) //key not found in the cache
    {
        if(cache.size() == cap) //cache at it's full capacity
        {
            int leastRecentlyUsedKey = cache.front(); // least recently used key at the front of the list
            cache.pop_front(); //least recently used key is popped out, to make space for incoming key
            cache_map.erase(leastRecentlyUsedKey);
        }
            cache.push_back(key); //incoming key pushed to the back, as it is the most recently used one
            cache_map[key] = value;
        }
        else{
            cache.remove(key); //the key is removed from it's current position and moved to the back, as it is most recently used
            cache.push_back(key);
            cache_map[key] = value;
        }
    }
};

int main()
{
    LRUCache* lru = new LRUCache(2);
    lru->put(1,1);
    lru->put(2,2);
    cout<<lru->get(1)<<endl;
    lru->put(3,3);
    cout<<lru->get(2)<<endl;
    lru->put(4,4);
    cout<<lru->get(1)<<endl;
    cout<<lru->get(3)<<endl;
    cout<<lru->get(4)<<endl;

    return 0;
}
