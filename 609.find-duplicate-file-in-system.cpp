/*
 * @lc app=leetcode id=609 lang=cpp
 *
 * [609] Find Duplicate File in System
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> M;
        for (const string& path : paths) {
            int i = path.find(' ');
            if (i == string::npos) continue;
            string dir = path.substr(0, i);
            i ++;
            for (; i < path.size();) {
                int j = path.find('(', i);
                int k = path.find(')', j);
                //cout << i << " " << j << " " << k << endl;
                string file = path.substr(i, j - i);
                string content = path.substr(j + 1, k - j - 1);
                M[content].push_back(dir + '/' + file);
                i = k + 2;
            }
        }
        vector<vector<string>> res;
        for (const auto& v : M) {
            if (v.second.size() > 1) res.push_back(v.second);
        }
        return res;
    }
};
// @lc code=end

