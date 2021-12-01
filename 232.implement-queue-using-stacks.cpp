/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
  stack<int> st1, st2;

  void refresh() {
    if (!st1.empty()) return;
    while (!st2.empty()) {
      st1.push(st2.top());
      st2.pop();
    }
  }

 public:
  MyQueue() {}

  void push(int x) { st2.push(x); }

  int pop() {
    refresh();
    int res = st1.top();
    st1.pop();
    return res;
  }

  int peek() {
    refresh();
    return st1.top();
  }

  bool empty() {
    refresh();
    return st1.empty();
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
