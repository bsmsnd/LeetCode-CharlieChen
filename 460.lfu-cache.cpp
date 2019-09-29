/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */
// #include <map>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    list<list<int>> bucket;
    unordered_map<int, int> key_value_map; // key -> val
    unordered_map<int, int> key_freq_map; // key -> freq
    unordered_map<int, list<list<int>>::iterator> freqMap; // freq -> bucket
    unordered_map<int, list<int>::iterator> nodeMap;
    int cap;
    int size = 0;

    void promote(int key)
    {
        if (key_value_map.find(key) == key_value_map.end())
            return;
        
        int f = key_freq_map[key];
        list<list<int>>::iterator head = freqMap[f];
        head->erase(nodeMap[key]);

        // find correct place to put
        list<list<int>>::iterator new_head = head;

        if (freqMap.find(f + 1) == freqMap.end()) // not found
        {
            bucket.insert(head, list<int>());
            new_head--; // pointing at f+1
            freqMap[f+1] = head;
        }
        else
            new_head--;

        new_head->push_front(key);
        
        // remove the list if empty
        if (head->empty())
        {
            bucket.erase(head);
            freqMap.erase(f);
        }
        
        // update maps
        key_freq_map[key]++;
        nodeMap[key] = new_head->begin();
        freqMap[f + 1] = new_head;

    }

    void RemoveLFU()
    {
        auto tail = bucket.end();tail--;
        int key = tail->back();
        int f = key_freq_map[key];
        
        tail->pop_back();

        key_value_map.erase(key);
        key_freq_map.erase(key);
        nodeMap.erase(key);

        if (tail->empty())
        {
            bucket.pop_back();
            freqMap.erase(f);
        }
    }

    void addUnit(int key, int val)
    {
        int f = 1;
        list<list<int>>::iterator head;
        if (freqMap.find(f) == freqMap.end())
        {
            bucket.push_back(list<int>());
            head = bucket.end();
            head--;
        }
        else
        {
            head = freqMap[f];
        }
        head->push_front(key);

        // update maps
        key_value_map[key] = val;
        key_freq_map[key] = 1;
        freqMap[f] = head;
        nodeMap[key] = head->begin();
        
    }

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        key_value_map.clear();
        key_freq_map.clear();
        freqMap.clear();
        nodeMap.clear();
    }
    
    int get(int key) {
        if (cap == 0)return -1;
        if (key_value_map.find(key) == key_value_map.end())
        {
            return -1;
        }
        else
        {
            promote(key);
            return key_value_map[key];
        }
    }
    
    void put(int key, int value) {
        if (cap == 0)return;
        if (key_value_map.find(key) == key_value_map.end())
        {
            while (size >= cap)
            {
                RemoveLFU();
                size--;
            }
            addUnit(key, value);
            size++;
        }
        else
        {
            key_value_map[key] = value;
            promote(key);
        }
        
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

