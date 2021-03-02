/*
 * @lc app=leetcode id=1095 lang=cpp
 *
 * [1095] Find in Mountain Array
 */

// @lc code=start
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length() - 1, peak = 0;
        while (l < r) {
            int m = (l + r) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1)) l = peak = m + 1;
            else r = m;
        }

        l = 0, r = peak;
        while (l < r) {
            int m = (l + r) / 2;
            int cur = mountainArr.get(m);
            if (cur == target) return m;
            if (cur < target) l = m + 1;
            else r = m;
        }
        if (mountainArr.get(l) == target) return l;
        l = peak, r = mountainArr.length() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            int cur = mountainArr.get(m);
            if (cur == target) return m;
            if (cur > target) l = m + 1;
            else r = m;
        }
        if (mountainArr.get(l) == target) return l;
        return -1;
    }
};
// @lc code=end

