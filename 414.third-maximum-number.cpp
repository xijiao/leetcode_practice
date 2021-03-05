/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int> top3;
        for (int n : nums) {
            bool found = false;
            for (int& top : top3) {
                if (top == n) {
                    found = true;
                    break;
                }
                if (n > top) swap(n, top);
            }
            if (!found && top3.size() < 3) top3.push_back(n);
        }

        return top3.size() == 3 ? top3[2] : top3[0];
    }
};
// @lc code=end

