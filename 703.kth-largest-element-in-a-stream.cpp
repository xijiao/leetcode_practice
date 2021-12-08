/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest {
  priority_queue<int, vector<int>, greater<>> PQ;
  int k;

 public:
  KthLargest(int k, vector<int>& nums) : k(k), PQ(nums.begin(), nums.end()) {}

  int add(int val) {
    PQ.push(val);
    while (PQ.size() > k) PQ.pop();
    return PQ.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
