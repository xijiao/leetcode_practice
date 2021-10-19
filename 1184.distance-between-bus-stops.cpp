/*
 * @lc app=leetcode id=1184 lang=cpp
 *
 * [1184] Distance Between Bus Stops
 */

// @lc code=start
class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int n = distance.size(), dis1 = 0, dis2;
        for (int i = start; i != destination; i = (i + 1) % n)
        {
            dis1 += distance[i];
        }
        dis2 = accumulate(distance.begin(), distance.end(), 0) - dis1;
        return min(dis1, dis2);
    }
};
// @lc code=end
