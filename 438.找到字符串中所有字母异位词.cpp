/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=20004
 *
 * [438] 找到字符串中所有字母异位词
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) {
            return {};
        }
        vector<int> sCounter(26);
        vector<int> pCounter(26);
        for(char ch: p) {
            pCounter[ch - 'a']++;
        }
        int pSize = p.size();
        for (int i = 0; i < pSize - 1; i++) {
            sCounter[s[i] - 'a']++;
        }
        int sSize = s.size();
        vector<int> answer;
        for (int i = pSize - 1; i < sSize; i++) {
            sCounter[s[i] - 'a']++;
            if (sCounter == pCounter) {
                answer.push_back(i - pSize + 1);
            }
            sCounter[s[i - pSize + 1] - 'a']--;
        }
        return answer;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

// @lcpr case=start
// "aaaaaaaaaa"\n"aaaaaaaaaaaaa"\n
// @lcpr case=end

 */

