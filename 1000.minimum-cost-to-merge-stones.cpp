/*
 * @lc app=leetcode id=1000 lang=cpp
 *
 * [1000] Minimum Cost to Merge Stones
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        int res = 0;
        for (; n >= K; n -= (K - 1)) {
            int curSum = 0;
            for (int i = 0; i < K; i++) {
                curSum += stones[i];
            }
            int minSum = curSum;
            int minStart = 0;
            for (int i = K; i < n; i++) {
                curSum += stones[i];
                curSum -= stones[i - K];
                if (curSum < minSum) {
                    minSum = curSum;
                    minStart = i - K + 1;
                }
            }

            cout << minStart << " " << minSum << endl;
            stones[minStart] = minSum;
            for (int i = minStart + 1; i < n - K + 1; i++) {
                stones[i] = stones[i + K - 1];
            }
            res += minSum;
        }
        if (n == 1) return res;
        else return -1;
    }
};
// @lc code=end

