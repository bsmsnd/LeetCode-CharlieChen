/*
 * @lc app=leetcode.cn id=面试题 16.25 lang=cpp
 * @lcpr version=30203
 *
 * [面试题 16.25] LRU 缓存
 */

// @lc code=start
#include "helper.h"
#include <sys/_types/_key_t.h>
class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity), count(0) {
        cache.clear();
        dict.clear();
    }

    int get(int key) {
        if (dict.find(key) != dict.end()) {
            promote(key);
            return dict[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (dict.find(key) == dict.end()) {
            cache.push_front(key);
            dict[key] = {value, cache.begin()};
            count++;
        } else {
            promote(key);
            dict[key].first = value;
        }
        while (count > cap) {
            drop(); // count will decrement within `drop`
        }
    }
private:
    void promote(int key) {
        if (dict.find(key) == dict.end()) {
            return;
        }
        cache.erase(dict[key].second);
        cache.push_front(key);
        dict[key].second = cache.begin();
    }

    void drop() {
        int key = cache.back();
        cache.pop_back();
        dict.erase(key);
        count--;
    }

private:
    list<int> cache;
    unordered_map<int, pair<int, list<int>::iterator>> dict;
    int cap;
    int count;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end



