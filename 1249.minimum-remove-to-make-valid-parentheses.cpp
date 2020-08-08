/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        unordered_set<int> remove_list;
        stack<int> l;

        const int N = s.size();
        for (int i = 0;i < N; i++)
            if (s[i] == '('){
                l.push(i);
            }
            else if (s[i] == ')'){
                if (l.empty())
                    remove_list.insert(i);
                else
                    l.pop();
            }

        while(!l.empty()){
            remove_list.insert(l.top());
            l.pop();
        }
        
        string ans;
        for (int i = 0;i < N; i++)
            if (remove_list.find(i) == remove_list.end())
                ans += s[i];
        return ans;
    }
};
// @lc code=end

