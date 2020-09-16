/*
 * @lc app=leetcode id=1562 lang=cpp
 *
 * [1562] Find Latest Group of Size M
 */

// @lc code=start
class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> length(n + 2), count(n + 1);
        int res = -1;
        for (int i = 0; i < arr.size(); i++) {
            int v = arr[i];
            int left = length[v - 1];
            int right = length[v + 1];
            length[v] = length[v - left] = length[v + right] = left + right + 1;
            count[left]--;
            count[right]--;
            count[left + right + 1]++;
            if (count[m] > 0) res = i + 1;
        }
        return res;
    }
};
// @lc code=end

