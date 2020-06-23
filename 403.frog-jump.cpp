/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1)return false;
        unordered_map<int, int> posToArr;
        const int N = stones.size();

        for (int i = 0;i < N; i++)
            posToArr[stones[i]] = i; 
        
        unordered_set<int> steps[N];
        steps[1].insert(1);
        int landing;
        for (int i = 1; i < N-1; i++){            
            for (auto f : steps[i]){
                // f - 1                
                if (f-1 > 0){
                    landing = stones[i] + f - 1;
                    auto it = posToArr.find(landing);
                    if (it != posToArr.end()){
                        steps[it->second].insert(f-1);
                    }
                }
                // f
                landing = stones[i] + f;
                auto it = posToArr.find(landing);
                if (it != posToArr.end()){
                    steps[it->second].insert(f);
                }
                // f + 1
                landing = stones[i] + f + 1;
                it = posToArr.find(landing);
                if (it != posToArr.end()){
                    steps[it->second].insert(f+1);
                }                
            }
        }

        return steps[N-1].size() > 0;
    }
};
// @lc code=end

