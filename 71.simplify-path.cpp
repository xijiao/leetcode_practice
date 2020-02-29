/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        deque<int> indexes;
        for (int i = 0; i < path.size();) {
            if (path[i] == '/') {
                i++;
                continue;
            }
            int n = 0;
            bool only_dot = true;
            for (; i + n < path.size() && path[i + n] != '/'; n++) {
                if (path[i + n] != '.') {
                    only_dot = false;
                }
            }

            if (only_dot && n == 2) {
                if (!indexes.empty()) {
                    indexes.pop_back();
                }
            } else if (!only_dot || n > 2) {
                indexes.push_back(i);
            }
            i += n;
        }

        if (indexes.empty()) {
            return "/";
        }
        int count = 0;
        for (int index : indexes) {
            path[count++] = '/';
            for (; index < path.size() && path[index] != '/';) {
                path[count++] = path[index++];
            }
        }
        path.resize(count);
        return path;
    }
};
// @lc code=end

