/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        unordered_set<int> opened;
        queue<int> q;
        opened.insert(0);
        q.push(0);
        for (; !q.empty();) {
            int cur = q.front(); q.pop();
            for (int next : rooms[cur]) {
                if (opened.count(next)) continue;
                opened.insert(next);
                q.push(next);
            }
        }
        return opened.size() == n;
    }
};
// @lc code=end

