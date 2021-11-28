/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
  stack<int> S;
  multiset<int> P;

 public:
  MinStack() {}

  void push(int val) {
    S.push(val);
    P.insert(val);
  }

  void pop() {
    P.erase(P.find(S.top()));
    S.pop();
  }

  int top() { return S.top(); }

  int getMin() { return *P.begin(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
