/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (string& str: tokens){
            if (str[0] == '+' && str.length() == 1){
                int a = s.top();
                s.pop();
                a += s.top();
                s.pop();
                s.push(a);
                continue;
            }

            if (str[0] == '-' && str.length() == 1){
                int a = -s.top();
                s.pop();
                a += s.top();
                s.pop();
                s.push(a);
                continue;
            }

            if (str[0] == '*'){
                int a = s.top();
                s.pop();
                a *= s.top();
                s.pop();
                s.push(a);
                continue;
            }

            if (str[0] == '/'){
                int a = s.top();
                s.pop();
                a = s.top() / a;
                s.pop();
                s.push(a);
                continue;
            }

            s.push(stoi(str));
        }
        return s.top();
    }
};
// @lc code=end

