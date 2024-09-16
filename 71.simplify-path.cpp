/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
#include "helper.h"

class Solution {
private:
    stack<string> stringStack;
public:
    void ProcessString(string& current) {
        if (current == ".") {
            return;
        }
        if (current == "..") {
            if (!stringStack.empty()) {
                stringStack.pop();
            }
            return;
        }
        if (current != "") {
            stringStack.push(current);
        }
        current = "";
    }

    void ReverseStack(stack<string>& st) {
        stack<string> tempStack;
        while (!st.empty()) {
            tempStack.push(st.top());
            st.pop();
        }
        swap(st, tempStack);
    }

    string simplifyPath(string path) {
        string current = "";
        for (char ch: path) {
            switch (ch) {
                case '/':
                    ProcessString(current);
                    break;
                default:
                    current += ch;
            }
        }
        ProcessString(current);
        ReverseStack(stringStack);
        string output = "/";
        while (!stringStack.empty()) {
            output += stringStack.top();
            stringStack.pop();
            if (!stringStack.empty()) {
                output += '/';
            }
        }
        return output;
    }
};
// @lc code=end

