/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */
#define NEW_BUILDING 1
#define END_BUILDING 2

struct event{
    int location;
    int event_type;
    int value;    
};

class MyCompare
{
public:
    bool operator()(const event&a, const event& b) const
    {
        return a.location > b.location;
    }
};

class Solution {
public:
    multiset<int, greater<int> > heights;
    priority_queue<event, vector<event>, MyCompare> events;
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int max_location = -1;
        vector<vector<int>> ans;
        for (int i = 0;i < buildings.size();++i)
        {
            event new_building;
            new_building.location = buildings[i][0];
            new_building.event_type = NEW_BUILDING;
            new_building.value = buildings[i][2];
            event end_building;
            end_building.location = buildings[i][1];
            end_building.event_type = END_BUILDING;
            end_building.value = buildings[i][2];
            events.push(new_building);
            events.push(end_building);    
            max_location = max(max_location, buildings[i][1]);        
        }
        int cur_height = 0;
        int cur_location;
        int new_height;
        event cur_event;
        bool change_flag;
        while(!events.empty())
        {
            // cout<<events.size()<<endl;
            cur_location = events.top().location;            
            while(!events.empty() && events.top().location == cur_location)
            {
                // cout<<events.size()<<endl;
                // cout<<events.top().location<<endl;
                
                cur_event = events.top();                
                events.pop();            
                switch (cur_event.event_type){
                    case NEW_BUILDING:
                        // cout<<"insert"<<endl;
                        heights.insert(cur_event.value);                        
                        break;
                    case END_BUILDING:
                        // cout<<"delete"<<endl;
                        heights.erase(heights.find(cur_event.value));
                        break;
                }                
            }
            if (!heights.empty())
                new_height = *heights.begin();
            else
                new_height = 0;
            if (new_height != cur_height)
            {
                cur_height = new_height;                
                vector<int> new_height_to_report;
                new_height_to_report.push_back(cur_location);
                new_height_to_report.push_back(cur_height);
                ans.push_back(new_height_to_report);
            }
        }
        return ans;
    }
};

