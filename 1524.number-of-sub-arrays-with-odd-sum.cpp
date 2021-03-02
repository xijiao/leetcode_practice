/*
 * @lc app=leetcode id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

// @lc code=start
class Solution {
    const int MOD = 1000000007;

public:
    int numOfSubarrays(vector<int>& arr) {

        int odds = 0, evens = 0, res = 0;
        for (int v : arr) {
            if (v % 2) {
                int tmp = odds;
                odds = evens + 1;
                evens = tmp;
            }
            else {
                evens++;
            }
            res = (res + odds) % MOD;
        }

        return res;
    }
};
// @lc code=end

