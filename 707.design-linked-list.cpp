/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start

// #include <__config>
// #include <complex>

struct LinkedListNode {
    int val;
    LinkedListNode *next = nullptr;
    LinkedListNode *prev = nullptr;
    LinkedListNode(int v) : val(v), next(nullptr), prev(nullptr) {};
};

class MyLinkedList {
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
        nOfNodes = 0;
    }
    
    int get(int index) {
        if (index >= nOfNodes) {
            return -1;
        }
        int cnt = 0;
        LinkedListNode *visit = head;
        while (cnt < index) {
            visit = visit->next;
            cnt++;
        }
        return visit->val;
    }
    
    void addAtHead(int val) {
        LinkedListNode *node = new LinkedListNode(val);
        if (head) {
            head->prev = node;
            node->next = head;
        } else {
            tail = node;
        }
        head = node;
        nOfNodes++;
    }
    
    void addAtTail(int val) {
        LinkedListNode *node = new LinkedListNode(val);
        if (tail) {
            tail->next = node;
            node->prev = tail;
        } else {
            head = node;
        }
        tail = node;
        nOfNodes++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > nOfNodes) {
            return;
        } else if (index == nOfNodes) {
            addAtTail(val);
        } else if (index == 0) {
            addAtHead(val);
        } else { // must be in the middle
            LinkedListNode *existNode = GetNthNode(index);
            LinkedListNode *nodeToAdd = new LinkedListNode(val);
            nodeToAdd->prev = existNode->prev;
            nodeToAdd->next = existNode;
            existNode->prev->next = nodeToAdd;
            existNode->prev = nodeToAdd;
            nOfNodes++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= nOfNodes) {
            return;
        }
        if (nOfNodes == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            nOfNodes--;
        } else if (index == 0) { 
            LinkedListNode *tmp = head;
            head = head->next;
            delete tmp;
            nOfNodes--;
        } else if (index == nOfNodes - 1) {
            LinkedListNode *tmp = tail;
            tail = tail->prev;
            delete tmp;
            nOfNodes--;
        } else {
            LinkedListNode *existNode = GetNthNode(index);
            existNode->next->prev = existNode->prev;
            existNode->prev->next = existNode->next;
            delete existNode;
            nOfNodes--;
        }
    }
private:
    LinkedListNode *head;
    LinkedListNode *tail;
    int nOfNodes;
    LinkedListNode* GetNthNode(int index) {
        if (index >= nOfNodes) {
            return nullptr;
        }
        LinkedListNode *visit = head;
        for (int i = 0; i < index; i++) {
            visit = visit->next;
        }
        return visit;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

