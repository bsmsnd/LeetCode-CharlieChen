/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */
class Solution {
public:
/* Hash table solution
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  // ?
        
        for (int i = 0; i < nums.size(); i++)
        {
            // i points to c
            if (i < nums.size() - 1 && nums[i] == nums[i + 1]) continue;
            unordered_set<int> num_map;
            for (int j = 0;j < i;j++)
            {
                if (num_map.count(-nums[i] - nums[j]))
                {
                    result.push_back({-nums[i] - nums[j], nums[j], nums[i]});
                    while (nums[j+1] == nums[j] && j < i - 1) j++;
                }                                    
                num_map.insert(nums[j]);
            }
        }
        return result;   
    }
*/

// two pointer solution
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int left,right;
        int lvalue,rvalue;
        int size = nums.size();
        for (int i = 2; i < size; i++)
        {
            if(i < nums.size() - 1 && nums[i] == nums[i+1]) continue;
            left = 0;
            right = i - 1;   
            while(right > left){            
                lvalue = nums[left];
                rvalue = nums[right];
                if (lvalue + rvalue + nums[i] == 0){
                    result.push_back({lvalue, rvalue, nums[i]});
                    while(right > left && nums[left] == lvalue) left++;
                    while(right > left && nums[right] == rvalue) right--;             
                }
                else if (nums[left] + nums[right] > -nums[i])
                {
                    // cout<<"test7"<<endl;
                    while(right > left && nums[right] == rvalue) right--;                 
                }
                else
                {
                    // cout<<"test8"<<endl;
                    while(right > left && nums[left] == lvalue) left++;
                }                              
            }
        }
        return result;
    }
};

