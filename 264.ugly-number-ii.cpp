/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */
#define min(a,b) ((a) < (b) ? (a) : (b))

class Solution {
public:
    int nthUglyNumber(int n) {
        int pointers[3] = {0,0,0};
        const int N = n;
        int ans[N];
        ans[0] = 1;
        int next;
        for (int i = 1; i < N; ++i)
        {
            next = min(min(ans[pointers[0]] * 2, ans[pointers[1]] * 3), ans[pointers[2]] * 5);
            ans[i] = next;
            if (ans[pointers[0]] * 2 == next) pointers[0]++;
            if (ans[pointers[1]] * 3 == next) pointers[1]++;
            if (ans[pointers[2]] * 5 == next) pointers[2]++;
        }
        return ans[N-1];
    }
};

