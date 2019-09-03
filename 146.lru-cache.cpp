/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
#include <vector>
#include <map>
using namespace std;

struct Cell{
    int key;
    int value;
    Cell *prev, *next;    
    Cell(int _key, int _val): key(_key), value(_val), prev(nullptr), next(nullptr){};
    Cell(): key(-1), value(-1), prev(nullptr), next(nullptr){};
    Cell(int _key, int _val, Cell* _prev, Cell* _next): key(_key), value(_val), prev(_prev), next(_next){};
};

class LRUCache {
public:         
    map<int, Cell*> m;
    int cnt;
    int cap;
    Cell *head, *tail;
    LRUCache(int capacity) {
        cap = capacity;
        cnt = 0;
        head = nullptr; 
        tail = nullptr;
    }
    
    int get(int key) {
        if (m.find(key) == m.end())
            return -1;
        else
        {
            move_to_tail(m[key]);
            return m[key]->value;
        }
        
    }
        
    void put(int key, int value) {
        if (m.find(key) == m.end())
        {
            if (!head)
            {
                head = new Cell(key, value, nullptr, nullptr);
                tail = head;
                cnt++;
                m[key] = head;
            }
            else if (cnt < cap)
            {
                cnt++;
                tail = new Cell(key, value, tail, nullptr);
                tail->prev->next = tail;
                m[key] = tail;
            }
            else
            {
                remove(head);
                cnt--;
                put(key, value);
                // m[key] = head;
            }
        }
        else
        {
            m[key]->value = value;
            move_to_tail(m[key]);
        }        
    }
private:
    void remove(Cell* node)
    {
        if (node->prev && node->next)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        else if (!node->prev)
        {
            head = node->next;
            if (node->next)
                node->next->prev = node->prev;                
        }
        else
        {
            tail = node->prev;
            node->prev->next = nullptr;
        }
        m.erase(node->key);
        free(node);
    }        
    void move_to_tail(Cell* node)
    {
        if (node==tail)return;

        if (node->prev && node->next)
        {
            node->prev->next = node->next;
            node->next->prev = node->prev;                        
        }                
        else if (!node->prev)
        {
            head = node->next;
            if (node->next)
                node->next->prev = node->prev;   
        }
        tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            tail = node;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

