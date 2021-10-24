/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), l = 0, r = m * n - 1;
        for (; l <= r;)
        {
            int mid = (l + r) / 2;
            int x = mid / n, y = mid % n;
            if (matrix[x][y] == target)
            {
                return true;
            }
            else if (matrix[x][y] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
