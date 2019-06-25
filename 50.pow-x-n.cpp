/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

class Solution {
public:
    unordered_map<int, double> power_map;    
    double func(int power)
    {
        auto it = power_map.find(power);
        if (it!=power_map.end())
            return power_map[power];
        if (power%2 != 0)
        {
            if (power > 0)
            {
                power_map[power] = func(power/2) * func(power/2 + 1);
                return power_map[power];
            }
            else
            {
                power_map[power] = func(power/2) * func(power/2 - 1);
                return power_map[power];
            }                        
        }
        else
        {
            power_map[power] = func(power/2) * power_map[power/2];
            return power_map[power];
        }
        
            
    }
    double myPow(double x, int n) {
        power_map[0] = 1.0;
        power_map[1] = x;
        power_map[-1] = 1/x;
        return func(n);
    }
};

