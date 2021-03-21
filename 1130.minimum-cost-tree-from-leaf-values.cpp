/*
 * @lc app=leetcode id=1130 lang=cpp
 *
 * [1130] Minimum Cost Tree From Leaf Values
 */

// @lc code=start
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<pair<int64_t, int>>> dp(n, vector<pair<int64_t, int>>(n, {0, 0})); // cost, maxleaf
        return find(arr, 0, n - 1, dp).first;
    }

    pair<int64_t, int> find(vector<int>& arr, int l, int r, vector<vector<pair<int64_t, int>>>& dp) {
        // cout << l << " " << r << endl;
        if (l == r) return {0, arr[l]};
        if (l + 1 == r) return {arr[l] * arr[r], max(arr[l], arr[r])};
        if (dp[l][r].first > 0) return dp[l][r];
        pair<int64_t, int> res = {INT_MAX, 0};
        for (int k = l; k < r; k++) {
            auto resl = find(arr, l, k, dp);
            auto resr = find(arr, k + 1, r, dp);
            if (resl.first + resr.first + resl.second * resr.second < res.first) {
                res.first = resl.first + resr.first + resl.second * resr.second;
                res.second = max(resl.second, resr.second);
            }
        }
        dp[l][r] = res;
        // cout << l << " " << r << " " << res.first << " " << res.second << endl;
        return res;
    }
};
// @lc code=end

