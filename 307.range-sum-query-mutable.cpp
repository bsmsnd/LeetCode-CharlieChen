/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
class NumArray {
public:
    // const int N = 100000;  // limit fir array size
    int n;
    vector<int> tree;
     
    NumArray(vector<int>& nums) {    
        n = nums.size();
        tree.resize(n * 2);
        for (int i = 0; i < n; i++)
            tree[n+i] = nums[i];
        for (int i = n-1;i > 0;i--)
            tree[i] = tree[i<<1] + tree[i<<1|1];
    }
    
    void update(int p, int val) {
        tree[p + n] = val;
        p = p + n;
        for (int i=p;i>1;i>>=1)
            tree[i>>1] = tree[i] + tree[i^1];  // ^: XOR            
    }
    
    int sumRange(int l, int r) {
        int res = 0;

        for(l+=n, r+=(n+1); l < r; l >>=1, r>>=1)
        {
            if (l & 1)
                res += tree[l++];
            if (r & 1)
                res += tree[--r];
        }
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */

