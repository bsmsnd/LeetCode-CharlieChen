/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
#include "helper.h"
#include <memory>

struct Node {
    string url_;
    Node* prev_;
    Node* next_;
    Node(string url) : url_(url), prev_(nullptr), next_(nullptr) {};
};

class BrowserHistory {
public:

    BrowserHistory(string homepage) {
        currentPage = make_unique<Node>(home)
    }

    void visit(string url) {
        currentPage->next_ = new Node(url);
        currentPage->next_->prev_ = currentPage;
        currentPage = currentPage->next_;
    }

    string back(int steps) {
        while(steps > 0) {
            steps--;
            if (currentPage->prev_ != nullptr) {
                currentPage = currentPage->prev_;
            } else {
                steps = 0;
            }
        }
        return currentPage->url_;
    }

    string forward(int steps) {
        while (steps > 0) {
            steps--;
            if (currentPage->next_ != nullptr) {
                currentPage = currentPage->next_;
            } else {
                steps = 0;
            }
        }
        return currentPage->url_;
    }
private:
    unique_ptr<Node> currentPage;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

