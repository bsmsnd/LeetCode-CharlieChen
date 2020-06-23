/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
struct Node{
    int val;
    Node* prev;
    Node* next;
};

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : size(k){
        front = rear = nullptr;
        curSize = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull())return false;
        
        Node* new_node = new Node;
        new_node->val = value;
        new_node->prev = nullptr;

        if (curSize == 0){
            new_node->next = nullptr;            
            front = rear = new_node;
        }
        else{            
            new_node->next = front;
            front->prev = new_node;
            front = new_node;       
        }        
        curSize++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull())return false;

        Node* new_node = new Node;
        new_node->val = value;
        new_node->next = nullptr;

        if (curSize == 0){
            new_node->prev = nullptr;            
            front = rear = new_node;
        }
        else{            
            new_node->prev = rear;
            rear->next = new_node;
            rear = new_node;       
        }        
        curSize++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty())return false;

        if (curSize == 1){            
            delete front;
            front = rear = nullptr;
        }
        else{
            Node* new_front = front->next;
            delete front;
            front = new_front;

        }
        curSize--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty())return false;

        if (curSize == 1){
            delete rear;
            front = rear = nullptr;            
        }
        else{
            Node* new_rear = rear->prev;
            delete rear;
            rear = new_rear;
        }
        curSize--;
        return true;        
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return front->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return rear->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return curSize == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return curSize >= size;
    }
private:
    Node* front;
    Node* rear;
    int curSize;
    int size;

};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

