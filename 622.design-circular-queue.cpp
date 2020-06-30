/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        front = rear = 0;
        size = 0;
        maxSize = k;
        q.resize(k, -1);        
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (size < maxSize){
            q[front] = value;
            size++;
            if (++front >= maxSize)
                front = 0;
            return true;
        }
        
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (size > 0){
            // int x = q[rear];
            size--;
            if (++rear >= maxSize)
                rear = 0;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (size == 0)return -1;
        return q[rear];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (size == 0)return -1;
        return front == 0 ? q[maxSize - 1] : q[front - 1];        
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size >= maxSize;
    }

    vector<int> q;
    int front, rear;
    int size;
    int maxSize;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

