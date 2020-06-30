/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start

const int T = 1000;
class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        v.resize(T);
    }
    
    void add(int key) {
        int place = key % T;
        if (find(v[place].begin(), v[place].end(), key) == v[place].end())
            v[place].push_back(key);
    }
    
    void remove(int key) {
        int place = key % T;
        list<int>::iterator loc = find(v[place].begin(), v[place].end(), key);
        if (loc != v[place].end())
            v[place].erase(loc);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int place = key % T;
        return find(v[place].begin(), v[place].end(), key) != v[place].end();
    }

private: 
    vector<list<int>> v;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end

