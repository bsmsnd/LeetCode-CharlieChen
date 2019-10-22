/*
 * @lc app=leetcode id=731 lang=cpp
 *
 * [731] My Calendar II
 */

// @lc code=start

#include <iostream>
#include <map>
using namespace std;

class MyCalendarTwo {
public:
    map<int, int> bookings;    
    MyCalendarTwo() {
        bookings.clear();
        bookings[0] = 0;
    }
    
    bool book(int start, int end) {
        bool flag = true;
        for (auto it = bookings.begin(); it != bookings.end(); it++)
        {
            if (it->first < start)
                continue;
            else
            {
                if (it->second > 1)
                {
                    cout<<it->first<<" "<<it->second<<endl;
                    flag = false;
                    break;
                }
                if (it->first >= end)break;
                
            }                            
        }
        if (!flag)
            return false;
        flag = false;
        for (auto it = bookings.begin(); it != bookings.end(); it++)
        {
            if (it->first < start)
                continue;
            else if (it->first == start){flag = true;break;}
            else {bookings[start] = it->second;flag = true;break;}
        }
        if (!flag)
            bookings[start] = 0;
        
        flag = false;
        for (auto it = bookings.find(start); it != bookings.end(); it++)
        {
            if (it->first == start)continue;
            if (it->first < end)
                it->second++;
            else if (it->second == end){flag = true;it->second++;break;}
            else {flag = true;bookings[end] = it->second + 1; break;}
        }
        if (!flag)
            bookings[end] = 1;
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

