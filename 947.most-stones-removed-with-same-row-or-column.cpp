/*
 * @lc app=leetcode id=947 lang=cpp
 *
 * [947] Most Stones Removed with Same Row or Column
 */

// @lc code=start
class Solution {
    unordered_map<int, int> u; // union of index
    int islands = 0;

public:
    int removeStones(vector<vector<int>>& stones) {
        for (const auto& s : stones) {
            uni(s[0], ~s[1]);
        }
        return stones.size() - islands;
    }

    int find(int k) {
        if (!u.count(k)) {
            u[k] = k;
            islands++;
        }
        if (u[k] != k) {
            u[k] = find(u[k]);
        }
        return u[k];
    }

    void uni(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            u[x] = y;
            islands--;
        }
    }

    

    // Brutal, Time Limit Exceeded
    // int removeStones(vector<vector<int>>& stones) {
    //     int total = stones.size();
    //     vector<vector<int>> backlog;
    //     bool found = false;
    //     unordered_set<int> xs, ys;
    //     int left = 0;
    //     for (;!stones.empty();) {
    //         for (const vector<int>& s : stones) {
    //             if (xs.empty() || xs.count(s[0]) || ys.count(s[1])) {
    //                 if (xs.empty()) left++;
    //                 found = true;
    //                 xs.insert(s[0]);
    //                 ys.insert(s[1]);
    //             } else {
    //                 backlog.push_back(s);
    //             }
    //         }
    //         if (!found) {
    //             xs.clear();
    //             ys.clear();
    //         }
    //         found = false;
    //         backlog.swap(stones);
    //         backlog.clear();
    //     }
    //     return total - left;
    // }
};
// @lc code=end

