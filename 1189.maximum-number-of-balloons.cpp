/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int, int> C1, C2;
        for (char c : string("balloon")) C1[c]++;
        for (char c : text) C2[c]++;
        int res = C2['b'];
        for (auto& kv : C1) {
            //cout << kv.first << " " << kv.second << endl;
            res = min(res, C2[kv.first] / kv.second);
        }
        return res;
    }
};
// @lc code=end

