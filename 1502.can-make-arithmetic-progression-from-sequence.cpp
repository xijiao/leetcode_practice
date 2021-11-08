/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start
class Solution {
 public:
  // O(nlogn), but faster....
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; i++) {
      if (arr[i + 2] - arr[i + 1] != arr[i + 1] - arr[i]) {
        return false;
      }
    }
    return true;
  }

  // O(n)
  //   bool canMakeArithmeticProgression(vector<int>& arr) {
  //     int minVal = arr[0], maxVal = arr[0];
  //     for (int a : arr) {
  //       minVal = min(minVal, a);
  //       maxVal = max(maxVal, a);
  //     }
  //     if ((maxVal - minVal) % (arr.size() - 1) != 0) return false;
  //     int gap = (maxVal - minVal) / (arr.size() - 1);
  //     if (gap == 0) return true;
  //     unordered_set<int> M;
  //     for (int a : arr) {
  //       M.insert(a - minVal);
  //     }
  //     if (M.size() != arr.size()) return false;
  //     for (auto& m : M) {
  //       if (m % gap != 0) return false;
  //     }
  //     return true;
  //   }
};
// @lc code=end
