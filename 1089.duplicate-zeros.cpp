/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        if (arr.size() <= 1) return;
        int zero_count = 0;
        for (int v : arr) {
            if (v == 0) zero_count ++;
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (i + zero_count < arr.size()) arr[i + zero_count] = arr[i];
            if (arr[i] == 0) {
                zero_count--;
                if (i + zero_count < arr.size()) arr[i + zero_count] = arr[i];
            }
        }
    }
};
// @lc code=end

