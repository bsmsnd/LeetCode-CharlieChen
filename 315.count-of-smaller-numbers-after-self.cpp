/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */
#include <vector>
#include <algorithm>
using namespace std;
class BST
{
public:
    struct node
    {
        int value;
        int cnt;
        int self_cnt;
        node* left;
        node* right;
    };
    
    node* root;
    node* reset(node* t)
    {
        if (t == nullptr)
            return nullptr;
        reset(t->left);
        reset(t->right);
        delete t;
        return nullptr;
    };
    
    
    BST()
    {
        root = nullptr;
    }
    
    node* insert(int newValue)
    {
        return insert(newValue, root);
    }
    
    node* insert(int newValue, node* t)
    {
        if (t == nullptr)
        {
            t = new node;
            t->value = newValue;
            t->cnt = 0;
            t->self_cnt = 1;
            t->left = t->right = nullptr;
        }
        else if (newValue > t->value)
            t->right = insert(newValue, t->right);
        else if (newValue < t->value)
        {
            t->left = insert(newValue, t->left);
            t->cnt++;
        }
        else
        {
            t->self_cnt++;
        }
        
        return t;
    };
    
    node* findMin(node* t)
    {
        if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }
    
    node* findMax(node* t)
    {
        if (t->right == nullptr)
            return t;
        else
            return findMin(t->right);
    }
    
    node* find(int x, node* t)
    {
        if (t == nullptr)
            return nullptr;
        if (x == t->value)
            return t;
        if (x > t->value)
            return find(x, t->right);
        // x < t->value
        return find(x, t->left);
    }
    
    node* remove(int x, node* t)
    {
        if (t == nullptr)
            return nullptr;
        node* tmp;
        if (x < t->value)
            return remove(x, t->left);
        else if (x > t->value)
            return remove(x, t->right);
        else  // x == t->value
        {
            if (t->left != nullptr && t->right != nullptr)
            {
                tmp = findMin(t->right);
                t->value = tmp->value;
                t->right = remove(t->value, t->right);
            }
            else
            {
                tmp = t;
                if (t->left == nullptr)
                    t = t->right;
                else if (t->right == nullptr)
                    t = t->left;
                delete tmp;
                
            }
            return t;
        }
    }
    
    int findSmaller(int s)
    {
        return findSmaller(s, root);
    }
    int findSmaller(int s, node* t)
    {
        if (t == nullptr)
            return 0;
        if (t->value == s)
            return t->cnt;
        if (s > t->value)
            return t->cnt + t->self_cnt + findSmaller(s, t->right);
        // s < t->value
        return findSmaller(s, t->left);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        BST binary_search_tree;
        vector<int> result;
        for (int i = nums.size() - 1;i>=0;--i)
        {
            result.push_back(binary_search_tree.findSmaller(nums[i]));
            binary_search_tree.root = binary_search_tree.insert(nums[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }

};

