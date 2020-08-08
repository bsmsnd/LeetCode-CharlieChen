/*
 * @lc app=leetcode id=360 lang=cpp
 *
 * [360] Sort Transformed Array
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> ans;
        const int N = nums.size();
        if (N == 0)return ans;
        if (N == 1){
            ans.push_back(a*nums[0]*nums[0] + b * nums[0] + c);
            return ans;
        }

        if (a == 0){
            if (b == 0){
                ans.resize(N, c);
                return ans;
            }
            else if (b > 0){
                for (int n : nums)
                    ans.push_back(b * n + c);
                return ans;
            }
            else{
                for (int i = N - 1; i >=0; i--)
                    ans.push_back(b * nums[i] + c);
                return ans;
            }
        }

        double x0 = -b / (2.0 * a);
        if (nums[0] >= x0 && nums.back() >= x0){
            if (a>0){
                for (int n : nums)
                    ans.push_back(a * n * n + b * n + c);
                return ans;
            }
            else{
                for (int i = N - 1; i >=0; i--)
                    ans.push_back(a * nums[i] * nums[i] + b * nums[i] + c);
                return ans;
            }            
        }
        else if (nums[0] <= x0 && nums.back() <= x0){
            if (a<0){
                for (int n : nums)
                    ans.push_back(a * n * n + b * n + c);
                return ans;
            }
            else{
                for (int i = N - 1; i >=0; i--)
                    ans.push_back(a * nums[i] * nums[i] + b * nums[i] + c);
                return ans;
            }  
        }

        int p1 = 0, p2 = N - 1;
        int place = 0;
        
        ans.resize(N, 0);
        
        while(p1 <= p2){
            int v1 = a * nums[p1] * nums[p1] + b * nums[p1] + c;
            int v2 = a * nums[p2] * nums[p2] + b * nums[p2] + c;
            if (a > 0){
                if (v1>=v2){
                    ans[N - 1 - place] = v1;
                    p1++;
                }
                else{
                    ans[N - 1 - place] = v2;
                    p2--;                    
                }
                place++;
            }
            else{
                if (v1>=v2){
                    ans[place++] = v2;
                    p2--;
                }
                else{
                    ans[place++] = v1;
                    p1++;
                }
            }
        }
        return ans;

    }
};
// @lc code=end

