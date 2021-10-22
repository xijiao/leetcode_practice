/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 */

// @lc code=start
class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int N = img1.size();
        vector<pair<int, int>> points1, points2;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (img1[i][j] == 1)
                    points1.push_back({i, j});
                if (img2[i][j] == 1)
                    points2.push_back({i, j});
            }
        }

        unordered_map<int, int> count;
        for (const pair<int, int> &point1 : points1)
        {
            for (const pair<int, int> &point2 : points2)
            {
                count[(point1.first - point2.first) * N * 2 + point1.second - point2.second]++;
            }
        }

        int res = 0;
        for (auto &c : count)
            res = max(res, c.second);
        return res;
    }
};
// @lc code=end
