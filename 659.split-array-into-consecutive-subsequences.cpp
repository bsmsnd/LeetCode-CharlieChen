/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        const int S = nums.size();
        bool flag;
        vector<pair<int, int>> seqs;
        int seq_size = 0;
        int left_most = 0;
        for(int i = 0; i < S;++i)
        {
            flag = false;
            for (int j = seq_size - 1; j >= left_most; --j)
                if (seqs[j].second == nums[i] - 1)
                {
                    flag = true;
                    seqs[j].second = nums[i];
                    break;
                }
                else
                {
                    if (nums[i] - seqs[j].second > 1)
                    {                        
                        
                        for (int k = left_most; k <= j; ++k)
                        if (seqs[k].second - seqs[k].first < 2)
                            return false;
                        left_most = j+1;
                    }
                        
                }
                
            if (!flag)
            {
                seqs.push_back(make_pair(nums[i],nums[i]));
                seq_size++;
            }
        }

        for (int i = left_most; i < seq_size; ++i)
        if (seqs[i].second - seqs[i].first < 2)
            return false;
        return true;                
    }
};

