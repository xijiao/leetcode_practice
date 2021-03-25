/*
 * @lc app=leetcode id=710 lang=cpp
 *
 * [710] Random Pick with Blacklist
 */

// @lc code=start
class Solution {
    unordered_map<int, int> _offset;
    int _MOD;
public:
    Solution(int N, vector<int>& blacklist) {
        _MOD = N - blacklist.size();
        unordered_set<int> B(blacklist.begin(), blacklist.end());
        int v = N - 1;
        for (int b : blacklist) {
            if (b >= _MOD) continue;
            while (B.count(v)) v--;
            _offset[b] = v--;
        }
    }
    
    int pick() {
        int r = rand() % _MOD;
        if (_offset.count(r)) return _offset[r];
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

