/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
private:
    queue<int> q_;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = q_.size();
        q_.push(x);
        for (int i = 0; i < n; i++) {
            int v = q_.front();
            q_.pop();
            q_.push(v);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = q_.front();
        q_.pop();
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return q_.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q_.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

