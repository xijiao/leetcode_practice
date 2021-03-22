/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) nums1.swap(nums2);
        unordered_map<int, int> count;
        for (int n : nums1) count[n]++;
        vector<int> res;
        for (int n : nums2) {
            if (count.count(n) && count[n] > 0) {
                count[n]--;
                if (count[n] == 0) count.erase(n);
                res.push_back(n);
            }
        }
        return res;
    }
};
// @lc code=end

