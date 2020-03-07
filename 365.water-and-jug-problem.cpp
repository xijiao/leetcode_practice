/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z == 0) return true;
        unordered_set<uint64_t> searched;
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        searched.emplace(0);
        while (!q.empty()) {
            auto t = q.front();
            q.pop_front();
            if (t.first == z || t.second == z || t.first + t.second == z) {
                return true;
            }
            helper(searched, q, {x, t.second});
            helper(searched, q, {t.first, y});
            helper(searched, q, {0, t.second});
            helper(searched, q, {t.first, 0});
            int pour_left = min(x - t.first, t.second);
            helper(searched, q, {t.first + pour_left, t.second - pour_left});
            int pour_right = min(y - t.second, t.first);
            helper(searched, q, {t.first - pour_right, t.second + pour_right});
        }
        return false;
    }

    void helper(unordered_set<uint64_t>& searched, deque<pair<int, int>>& q,
            const pair<int, int>& t) {
        if (t.first < 0 || t.second < 0) return;
        if (searched.find((long long)t.first << 32 | t.second) == searched.end()) {
            q.push_back(t);
            searched.emplace((long long)t.first << 32 | t.second);
        }
    }
};
// @lc code=end

