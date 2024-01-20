/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 */

// @lc code=start
// #include "helper.h"
struct Node {
    int value;
    int pos;
    int prefixSum;
    Node(int v, int p, int ps) : value(v), pos(p), prefixSum(ps) {};
};

constexpr int modulo = 1e9 + 7;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<Node> s;
        int accumulateSum = 0;
        int sum = 0;
        int N = arr.size();
        for (int i = 0; i < N; i++) {
            int prevPos = 0;
            while (!s.empty()) {
                const Node &node = s.top();
                if (arr[i] < node.value) {
                    accumulateSum -= node.prefixSum;
                    s.pop();
                } else {
                    prevPos = node.pos + 1;
                    break;
                }
            }
            accumulateSum += arr[i] * (i - prevPos + 1);
            s.push({arr[i], i, arr[i] * (i - prevPos + 1)});
            sum = ((sum % modulo) + (accumulateSum % modulo)) % modulo;
        }
        return sum;
    }
};
// @lc code=end

