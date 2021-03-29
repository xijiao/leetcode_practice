/*
 * @lc app=leetcode id=480 lang=cpp
 *
 * [480] Sliding Window Median
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double> res;
        for (int i = k; i <= nums.size(); i++) {
            //cout << nums[i] << " " << std::distance(window.begin(), mid) << endl;
            res.push_back((double(*mid) + *prev(mid, (k + 1) % 2)) / 2);
            if (i == nums.size()) return res;
            window.insert(nums[i]);
            if (nums[i] < *mid) --mid;
            if (nums[i - k] <= *mid) ++mid;
            window.erase(window.lower_bound(nums[i - k]));       
        }
        return res;
    }
};
// @lc code=end

