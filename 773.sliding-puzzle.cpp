/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_set<string> visited;
        deque<string> q;
        string start;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int c = board[i][j];
                start.push_back(c + '0');
            }
        }
        visited.emplace(start);
        q.emplace_back(start);
        const vector<vector<int>> DIRS = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        int res = 0;
        while (!q.empty()) {
            for (int count = q.size(); count > 0; count--) {
                string cur = q.front(); q.pop_front();
                if (cur == "123450") return res;
                visited.emplace(cur);
                int index = find(cur.begin(), cur.end(), '0') - cur.begin();
                for (int toswap : DIRS[index]) {
                    swap(cur[index], cur[toswap]);
                    if (visited.find(cur) == visited.end()) {
                        visited.emplace(cur);
                        q.emplace_back(cur);
                    }
                    swap(cur[index], cur[toswap]);
                }
            }
            res++;
        }
        return -1;        
    }
};
// @lc code=end

