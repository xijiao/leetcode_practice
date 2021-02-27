/*
 * @lc app=leetcode id=1508 lang=cpp
 *
 * [1508] Range Sum of Sorted Subarray Sums
 */

// @lc code=start
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> numbers; numbers.reserve(n * (n + 1) / 2);
        for (int i = 0; i < nums.size(); i++) {
            int cur = 0;
            for (int j = i; j >= 0; j--) {
                cur += nums[j];
                numbers.push_back(cur);
            }
        }
        sort(numbers.begin(), numbers.end());
        // for (int n : numbers) {
        //     cout << n << " ";
        // }
        // cout << endl;
        int res = 0;
        const int MOD = 1000000007;
        for (int i = left - 1; i < right; i++) {
            res = (res + numbers[i]) % MOD;
        }
        return res;
    }
};
// @lc code=end

