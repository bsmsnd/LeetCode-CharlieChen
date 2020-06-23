/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        if (N == 0)return 0;
        
        int ans[N][2];
        bool available[N][2];

        if (nums[0] > 0){
            available[0][0] = true;
            available[0][1] = false;
            ans[0][0] = nums[0];
        }
        else if (nums[0] < 0){
            available[0][0] = false;
            available[0][1] = true;
            ans[0][1] = nums[0];
        }
        else{
            available[0][0] = available[0][1] = false;            
        }
        int best = nums[0];

        for (int i = 1; i < N; i++){
            if (nums[i] > 0){
                ans[i][0] = max(nums[i], available[i-1][0] ? nums[i] * ans[i-1][0] : 0);
                available[i][0] = true;

                if (available[i-1][1]){
                    ans[i][1] = ans[i-1][1] * nums[i];
                    available[i][1] = true;
                }
                else
                    available[i][1] = false;
            }
            else if (nums[i] < 0){
                ans[i][1] = min(nums[i], available[i-1][0] ? nums[i] * ans[i-1][0] : 0);
                available[i][1] = true;

                if (available[i-1][1]){
                    ans[i][0] = nums[i] * ans[i-1][1];
                    available[i][0] = true;
                }
                else{
                    available[i][0] = false;
                }
            }
            else{
                available[i][0] = available[i][1] = false;
            }            
            
            if (available[i][0]) best = max(best, ans[i][0]);
            if (available[i][1]) best = max(best, ans[i][1]);
            if (nums[i] == 0) best = max(0, best);            
        }        
        return best;
        
    }
};
// @lc code=end

