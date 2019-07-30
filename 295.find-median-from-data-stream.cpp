/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    vector<int> s;
    int size;
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if (size == 0)
            s.push_back(num);
        else
            s.insert(lower_bound(s.begin(), s.end(), num), num);        
        size++;
    }
    
    double findMedian() {
        // cout<<size<<endl;
        return ((size&1) == 1) ? s[size/2] : (s[size/2] + s[size/2-1]) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

