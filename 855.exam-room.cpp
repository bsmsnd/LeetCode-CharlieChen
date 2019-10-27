/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

class Cmp
{
    public: 
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);
    }
};

class ExamRoom {
public:
    priority_queue<pair<int, int>, vector< pair<int, int> >, Cmp > q;// need review
    // deque<int> room;
    // unordered_map<int, deque<int>::iterator> toDeque;
    set<int> room;        
    int nStudents = 0;
    int roomSize;
    ExamRoom(int N) {
        room.clear();
        nStudents = 0;
        roomSize = N;
    }
    
    int seat() {
        if (nStudents >= roomSize)return -1; // should not happen

        if (nStudents == 0)
        {
            room.insert(0); 
            nStudents++;
            return 0;
        }
        else if (nStudents == 1)
        {            
            int choose = (*room.begin() - 0) >= (roomSize - 1 - *room.begin()) ? 0 : roomSize - 1;
            room.insert(choose);
            nStudents++;
            return choose;
        }
        else
        {
            // search all intervals
            int choose = -1;
            int best_interval = -1;
            
            // check if 0 is occupied
            if (*room.begin() != 0)
            {
                choose = 0;
                best_interval = *room.begin() - 0;                
            }

            auto it = room.begin();
            while(it!=room.end())
            {
                int l = *it, r, tmpDist, tmpChoose;
                it++;
                if (it == room.end())
                {
                    if (l != roomSize - 1)
                    {
                        tmpDist = roomSize - 1 - l;
                        if (best_interval == -1 ||tmpDist > best_interval)
                        {
                            choose = roomSize - 1;
                            best_interval = roomSize - 1 - l;
                        }
                    }
                    break; // should always use this to exit the loop
                }                        
                r = *it;
                tmpChoose = (l + r) / 2;
                tmpDist = tmpChoose - l;
                if (best_interval == -1 || tmpDist > best_interval)
                {
                    choose = tmpChoose;
                    best_interval = tmpDist;
                }
                // cout << l << " " << r << " " << tmpChoose << " " << choose << " " << best_interval << endl; 
            }
            nStudents++;
            room.insert(choose);
            return choose;
        }        
    }
    
    void leave(int p) {
        room.erase(p);
        nStudents--;
    }    
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

