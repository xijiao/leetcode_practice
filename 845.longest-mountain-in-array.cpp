/*
 * @lc app=leetcode id=845 lang=cpp
 *
 * [845] Longest Mountain in Array
 */

// @lc code=start
class Solution {
    enum {
        kAccending,
        kDecending,
        kInvalid,
    };
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        int curstart = 0;
        int state = kInvalid;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                state = kInvalid;
            } else if (arr[i] > arr[i - 1]) {
                if (state != kAccending) {
                    state = kAccending,
                    curstart = i - 1;
                }
            } else {
                if (state == kAccending) {
                    state = kDecending;
                }
                if (state == kDecending) {
                    res = max(res, i - curstart + 1);
                }
            }
        }
        return res;
    }
};
// @lc code=end

