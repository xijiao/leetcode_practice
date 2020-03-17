/*
 * @lc app=leetcode id=1073 lang=cpp
 *
 * [1073] Adding Two Negabinary Numbers
 */

// @lc code=start
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int carry = 0;
        vector<int> res(max(arr1.size(), arr2.size()) + 2, 0);
        for (int i = arr1.size() - 1, j = arr2.size() - 1, k = res.size() - 1;
                k >= 0; i--, j--, k--) {
            int v = carry;
            if (i >= 0) v += arr1[i];
            if (j >= 0) v += arr2[j];
            carry = v == -1 ? 1 : (v / 2) * -1;
            res[k] = v == -1 ? 1 : (v % 2);
        }

        // for (int v : res) {
        //     cout << v << " ";
        // }
        // cout << endl;
        int index = 0;
        while (index != res.size() && res[index] == 0) index++;
        if (index == res.size()) return {0};
        else return {res.begin() + index, res.end()};
    }
};
// @lc code=end

