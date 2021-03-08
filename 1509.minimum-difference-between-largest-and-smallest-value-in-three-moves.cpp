/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 */

// @lc code=start
class Solution {
public:
    int minDifference(vector<int>& nums) {
        vector<int> targets; // largest 4 + least 4, sorted
        getTargets(nums, targets);
        // for (int t : targets) {
        //     cout << t << " ";
        // }
        // cout << endl;
        int n = targets.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, -1)));
        return find(targets, dp, 0, n - 1, 3);
    }

    void getTargets(vector<int>& nums, vector<int>& targets) {
        if (nums.size() <= 8) {
            targets = nums;
            sort(targets.begin(), targets.end());
            return;
        }
        for (int n : nums) {
            if (targets.size() < 8) {
                bool inserted = false;
                for (int i = 0; i < targets.size(); i++) {
                    if (targets[i] > n) {
                        targets.insert(targets.begin() + i, n);
                        inserted = true;
                        break;
                    }
                }
                if (!inserted) {
                    targets.push_back(n);
                }
            } else {
                int inserted = false;
                for (int i = 0; i < 4; i++) {
                    if (targets[i] > n) {
                        swap(targets[i], n);
                        inserted = true;
                    }
                }
                if (inserted) continue;
                for (int i = 7; i >= 4; i--) {
                    if (targets[i] < n) {
                        swap(targets[i], n);
                    }
                }
            }
        }
    }

    int find(vector<int>& targets, vector<vector<vector<int>>>& dp, int l, int r, int left) {
        if (r - l <= left) return 0;
        if (left == 0) return targets[r] - targets[l];
        if (dp[l][r][left] != -1) return dp[l][r][left];
        int res = min(find(targets, dp, l + 1, r, left - 1), find(targets, dp, l, r - 1, left - 1));
        dp[l][r][left] = res;
        // cout << l << " " << r << " " << left << " " << res << endl;
        return res;
    }
};
// @lc code=end

