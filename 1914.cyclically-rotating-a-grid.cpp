/*
 * @lc app=leetcode id=1914 lang=cpp
 *
 * [1914] Cyclically Rotating a Grid
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> rotateGrid(vector<vector<int>> &grid, int k)
    {
        int m = grid.size(), n = grid[0].size();
        for (int layer = 0; layer < min(m, n) / 2; layer++)
        {
            vector<int> values;

            for (int i = layer; i < n - layer - 1; i++)
                values.push_back(grid[layer][i]);
            for (int i = layer; i < m - layer - 1; i++)
                values.push_back(grid[i][n - layer - 1]);
            for (int i = n - layer - 1; i > layer; i--)
                values.push_back(grid[m - layer - 1][i]);
            for (int i = m - layer - 1; i > layer; i--)
                values.push_back(grid[i][layer]);

            int offset = k % values.size();
            // cout << layer << ": ";
            // for (int v : values)
            //     cout << v << " ";
            // cout << endl;

            for (int i = layer; i < n - layer - 1; i++)
                grid[layer][i] = values[offset++ % values.size()];
            for (int i = layer; i < m - layer - 1; i++)
                grid[i][n - layer - 1] = values[offset++ % values.size()];
            for (int i = n - layer - 1; i > layer; i--)
                grid[m - layer - 1][i] = values[offset++ % values.size()];
            for (int i = m - layer - 1; i > layer; i--)
                grid[i][layer] = values[offset++ % values.size()];
        }
        return grid;
    }
};
// @lc code=end
