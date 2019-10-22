/*
 * @lc app=leetcode id=981 lang=cpp
 *
 * [981] Time Based Key-Value Store
 */

// @lc code=start
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> m;
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        if (m.find(key) == m.end())
            m[key] = map<int, string>();
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end())return "";
        auto it = m[key].lower_bound(timestamp);
        if (it == m[key].begin())
            if (it->first == timestamp)
                return it->second;
            else
                return "";
        else
        {
            if (it == m[key].end())it--;
            
            if (it->first <= timestamp)
                return it->second;
            else
                return (--it)->second;            
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

