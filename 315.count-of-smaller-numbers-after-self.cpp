/*
 * @lc app=leetcode id=315 lang=cpp
 *
 * [315] Count of Smaller Numbers After Self
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> indexes(n);
        vector<int> res(n, 0);
        vector<int> tmp_indexes(n);
        iota(indexes.begin(), indexes.end(), 0);

        // bottom up mergesort
        for (int w = 1; w < n; w *= 2) {
            for (int l = 0; l < n; l += (w * 2)) {
                int m = min(l + w, n);
                int r = min(m + w, n);
                int rightcount = 0;
                for (int k = l, i = l, j = m; k < r;) {
                    if (j >= r || (i < m && nums[indexes[i]] <= nums[indexes[j]])) {
                        tmp_indexes[k++] = indexes[i];
                        res[indexes[i]] += rightcount;
                        i++;
                    } else {
                        tmp_indexes[k++] = indexes[j++];
                        rightcount++;
                    }
                }
            }
            tmp_indexes.swap(indexes);
        }

        return res;
    }
};
// @lc code=end

