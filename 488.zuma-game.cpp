/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 */

// @lc code=start
class Solution {
public:
    int findMinStep(string board, string hand) {
        unordered_map<int, int> boardchars;
        for (char b : board) {
            boardchars[b]++;
        }
        unordered_map<int, int> H;
        for (char h : hand) {
            if (!boardchars.count(h)) continue;
            H[h]++;
        }
        for (const auto& bc : boardchars) {
            int total = bc.second;
            if (H.count(bc.first)) total += H[bc.first];
            if (total < 3) return -1;
        }
        unordered_map<string, int> cache;
        int res = dfs(board, H, cache);
        return res;
    }

    string makeKey(const string& board, unordered_map<int, int>& H) {
        stringstream ss;
        ss << board << "#";
        for (const auto& v : H) {
            ss << (char)v.first << v.second;
        }
        return ss.str();
    }

    int dfs(string board, unordered_map<int, int>& H, unordered_map<string, int>& cache) {
        reduce(board);
        if (board.empty()) return 0;
        if (H.empty()) return -1;
        string key = makeKey(board, H);
        if (cache.count(key)) return cache[key];
        int res = -1;
        for (int i = 0; i < board.size(); i++) {
            char c = board[i];
            //if (i > 0 && board[i - 1] == c) continue;
            for (char h = 'A'; h <= 'Z'; h++) {
                if (!H.count(h)) continue;
                H[h]--;
                if (!H[h]) H.erase(h);
                int r = dfs(board.substr(0, i) + h + board.substr(i), H, cache);
                H[h]++;
                //cout << r << endl;
                if (r == -1) continue;
                if (res == -1) res = r + 1;
                else res = min(res, r + 1);
            }
        }
        cache[key] = res;
        return res;
    }

    void reduce(string& board) {
        // cout << board << "->";
        bool reduced = true;
        while (reduced) {
            reduced = false;
            for (int i = 0, j = 0; j < board.size();) {
                while (j < board.size() - 1 && board[j] == board[j + 1]) j++;
                if (j - i >= 2) {
                    reduced = true;
                    for (int k = j + 1; k < board.size(); k++) {
                        board[k - j + i - 1] = board[k];
                    }
                    board.resize(board.size() - j + i - 1);
                    break;
                } else {
                    j++;
                    i = j;
                }
            }
        }
        // cout << board << endl;
    }

};
// @lc code=end

