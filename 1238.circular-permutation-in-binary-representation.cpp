/*
 * @lc app=leetcode id=1238 lang=cpp
 *
 * [1238] Circular Permutation in Binary Representation
 */

// @lc code=start
class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> res = createPermu(n);
        movePermu(res, start);
        return res;
    }

    vector<int> createPermu(int n) {
        vector<int> res = {0, 1};
        for (int i = 1; i < n; i++) {
            for (int j = res.size() - 1; j >= 0; j--) {
                res.push_back((1 << i) + res[j]);
            }
        }
        return res;
    }

    void movePermu(vector<int>& res, int start) {
        auto it = find(res.begin(), res.end(), start);
        reverse(res.begin(), it);
        reverse(it, res.end());
        reverse(res.begin(), res.end());
    }
};
// @lc code=end

