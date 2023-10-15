/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

#include "helper.h"
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int inputKey, int inputValue): key(inputKey), value(inputValue), prev(nullptr), next(nullptr) {};
};

class LRUCache {
public:
    LRUCache(int capacity) {
        head = nullptr;
        tail = nullptr;
    }

    int get(int key) {
        if (cache_.find(key) == cache_.end()) {
            return -1;
        }
        Node &result = cache_[key];
        if ()
        MoveToTail(result);
        if ()
        return result.value;
    };

    void put(int key, int value) {
        if
    }

    void MoveToTail(Node &node) {
        if (node.prev != nullptr) {
            node.prev->next = node.next;
        }
        if (node.next != nullptr) {
            node.next->prev = node.prev;
        }
        if (tail != nullptr) {
            tail->next = &node;
        }
        node.prev = tail;
        tail = &node;
    }
private:
    unordered_map<int, Node> cache_;
    Node *head;
    Node *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

