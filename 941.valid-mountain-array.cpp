/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int index = 1;
        for (; index < arr.size() && arr[index - 1] < arr[index]; index++);
        if (index == 1 || index == arr.size()) return false;
        for (; index < arr.size() && arr[index - 1] > arr[index]; index++);
        return index == arr.size();

    }
};
// @lc code=end

