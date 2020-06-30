/*
 * @lc app=leetcode id=1172 lang=cpp
 *
 * [1172] Dinner Plate Stacks
 */

// @lc code=start
class DinnerPlates {
public:
    DinnerPlates(int capacity) : cap(capacity) {
        // totPlates = 0;
        maxStack = -1;
    }
    
    void push(int val) {
        if (s.empty()){
            if (maxStack == -1 || plates[maxStack].size() >= cap){
                // new layer
                maxStack++;
                // remaining.push_back(cap-1);
                stack<int> newLayer;
                newLayer.push(val);
                plates.push_back(newLayer);            
            }
            else{
                // remaining[maxStack]--;
                plates[maxStack].push(val);
            }
        }
        else{
            int layerToUse = *(s.begin());            
            // if (--remaining[layerToUse] == 0)
            //     s.erase(layerToUse);
            plates[layerToUse].push(val);
            if (plates[layerToUse].size() >= cap)
                s.erase(layerToUse);
        }
    }
    
    int pop() {
        if (maxStack == -1)
            return -1;
        int x = plates[maxStack].top();
        plates[maxStack].pop();
        // remaining[maxStack]++;

        while (maxStack >= 0 && plates[maxStack].empty()){
            plates.pop_back();
            // remaining.pop_back();

            if (s.find(maxStack) != s.end())
                s.erase(maxStack);       
            maxStack--;
        }
        return x;
    }
    
    int popAtStack(int index) {
        if (index == maxStack)
            return pop();
        if (index > maxStack || plates[index].empty())
            return -1;
        
        int x = plates[index].top();
        plates[index].pop();
        // remaining[index]++;
        s.insert(index);
        return x;
    }
private:
    vector<stack<int>> plates;
    set<int> s;
    // vector<int> remaining;
    // int totPlates;
    int cap;
    int maxStack;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// @lc code=end

