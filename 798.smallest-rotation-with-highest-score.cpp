/*
 * @lc app=leetcode id=798 lang=cpp
 *
 * [798] Smallest Rotation with Highest Score
 */

// @lc code=start
class Solution {
public:
    int bestRotation(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, 0);
        // (i - K + n) % n = A[i] - 1
        // K = (i - A[i] + 1 + n) % n
        for (int i = 0; i < n; i++) dp[(i - A[i] + 1 + n) % n]--;
        for (int i = 1; i < n; i++) dp[i] += dp[i - 1] + 1;
        // for (int v : dp) cout << v << " ";
        // cout << endl;
        return distance(dp.begin(), max_element(dp.begin(), dp.end()));
    }
    // Time Limit Exceeded
    // int bestRotation(vector<int>& A) {
    //     int n = A.size();
    //     vector<int> dp(n, 0);
    //     for (int i = 0; i < n; i++) {
    //         // j = (i - K + n) % n
    //         // K = (i - j + n) % n
    //         for (int j = A[i]; j < n; j++) dp[(i - j + n) % n]++;
    //     }
    //     int maxV = dp[0], maxK = 0;
    //     for (int k = 1; k < n; k++) {
    //         if (dp[k] > maxV) {
    //             maxV = dp[k];
    //             maxK = k;
    //         }
    //     }
    //     return maxK;
    // }
};
// @lc code=end

