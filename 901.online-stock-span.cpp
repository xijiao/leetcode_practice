/*
 * @lc app=leetcode id=901 lang=cpp
 *
 * [901] Online Stock Span
 */

// @lc code=start
class StockSpanner {
  stack<pair<int, int>> st;  // price, count

 public:
  StockSpanner() {}

  int next(int price) {
    int res = 1;
    while (!st.empty() && st.top().first <= price) {
      res += st.top().second;
      st.pop();
    }
    st.push({price, res});
    return res;
  }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
