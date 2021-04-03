/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int postmax = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int newpostmax = max(arr[i], postmax);
            arr[i] = postmax;
            postmax = newpostmax;
        }
        return arr;
    }
};
// @lc code=end

