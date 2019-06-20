/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

#define LEFT(x) (x*2+1)
#define RIGHT(x) (x*2+2)

class Solution {
public:
    vector<int> heap;
    int size;

    void heapify(int l)
    {
        if (LEFT(l) >= size)
            return;
        if (LEFT(l) < size && RIGHT(l) == size)
        {
            if (heap[LEFT(l)] > heap[l])
                swap(heap[LEFT(l)], heap[l]);
            return;
        }

        if (heap[LEFT(l)] > heap[RIGHT(l)])
        {
            if (heap[l] < heap[LEFT(l)])
            {
                swap(heap[l], heap[LEFT(l)]);
                heapify(LEFT(l));
            }
        }
        else
        {
            if (heap[l] < heap[RIGHT(l)])
            {
                swap(heap[l], heap[RIGHT(l)]);
                heapify(RIGHT(l));
            }
        }        
    }
    void build_heap()
    {
        for (int i = size/2;i >=0; --i)
            heapify(i);
    }

    int findKthLargest(vector<int>& nums, int k) {
        heap = nums;
        size = nums.size();
        build_heap();        
        for(int i = 0;i < k-1;i++)
        {
            swap(heap[0], heap[size-1]);
            size--;
            heapify(0);            
        }        
        return heap[0];
    }
};

