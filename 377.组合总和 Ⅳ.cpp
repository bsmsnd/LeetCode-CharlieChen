/*
 * @lc app=leetcode.cn id=377 lang=cpp
 * @lcpr version=30202
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
// #include "helper.h"

const size_t MAX_TARGET = 1000;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        uint32_t sumCount[MAX_TARGET + 1] = {};
        sumCount[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j : nums) {
                if (i < j) {
                    continue;
                }

                if (sumCount[i - j] > 0) {
                    sumCount[i] += sumCount[i - j];
                }
            }
        }
        return sumCount[target];
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n4\n
// @lcpr case=end

// @lcpr case=start
// [9]\n3\n
// @lcpr case=end

// @lcpr case=start
[10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111]\n999\n
// @lcpr case=end
 */

