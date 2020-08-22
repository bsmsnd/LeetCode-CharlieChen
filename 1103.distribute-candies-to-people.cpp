/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

// @lc code=start
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int l = 1, r = sqrt(2 * candies) + 2;
        while(r - l > 1){
            int m = (l+r)/2;
            if ((m*m + m) / 2 <= candies)
                l = m;
            else
                r = m;
        }
        vector<int> ans;
        ans.resize(num_people, 0);
        int round = l / num_people;       
        cout << l << " " << round << endl; 

        for (int i = 0;i < num_people; i++)
            ans[i] = round * ((round - 1) * num_people + 2 * (i+1)) / 2;
        for (int i = 0; i < l%num_people; i++)
            ans[i] += (round * num_people + i + 1);
        int remain = candies - ((l+1) * l / 2), who = l % num_people;

        cout << remain << " " << who;
        ans[who] += remain;
        return ans;
    }
};
// @lc code=end

