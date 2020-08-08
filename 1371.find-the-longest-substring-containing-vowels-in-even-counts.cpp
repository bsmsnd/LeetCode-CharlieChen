/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
class Solution {
public:
    void printBinary(int s){
        while(s > 0){
            cout << (s & 1);
            s = (s>>1);
        }
        cout << endl;
    }
    int findTheLongestSubstring(string s) {
        unordered_map<int, int> pos;
        int cur = 0, ans = 0;
        pos[0] = -1;
        for (int i = 0;i < s.size(); i++){
            switch (s[i]){
                case 'a':
                    cur = cur ^ 1;
                    break;
                case 'e':
                    cur = cur ^ (1 << 1);
                    break;
                case 'i':
                    cur = cur ^ (1 << 2);
                    break;
                case 'o':
                    cur = cur ^ (1 << 3);
                    break;
                case 'u':
                    cur = cur ^ (1 << 4);
                    break;
            }
            // printBinary(cur);
            if (pos.find(cur) == pos.end())
                pos[cur] = i;
            else
                ans = max(ans, i - pos[cur]);
        }
        return ans;
    }
};
// @lc code=end
