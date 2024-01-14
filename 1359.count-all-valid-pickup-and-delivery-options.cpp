/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
public:
    static constexpr int MODULO = 1e9+7;
    int ModuloMultiply(int a, int b) {
        return ((int64_t)(a % MODULO)) * ((int64_t)(b % MODULO)) % MODULO;
    }
    int countOrders(int n) {
        int options[n+1];
        options[1] = 1;
        for (int i = 2; i <= n; i++) {
            options[i] = ModuloMultiply(ModuloMultiply(options[i-1], i), 2*i-1);
        }
        return options[n];
    }
};
// @lc code=end

