/*
 * @lc app=leetcode id=1013 lang=cpp
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
 */

// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for (int v : arr) sum += v;
        if (sum % 3) return false;
        int i = 0, j = arr.size() - 1;
        int subsum = 0;
        for (; i < arr.size(); i++) {
            subsum += arr[i];
            if (subsum == sum / 3) break;
        }
        if (i == arr.size()) return false;
        subsum = 0;
        for (; j >= 0; j--) {
            subsum += arr[j];
            if (subsum == sum / 3) break;
        }
        return i + 1 < j;
    }
};
// @lc code=end

