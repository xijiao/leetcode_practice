/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int res = 0;
        deque<int> st;
        for (const string& s : ops) {
            if (s == "+") {
                int p = *st.rbegin() + *(st.rbegin() + 1);
                res += p;
                st.push_back(p);
            } else if (s == "D") {
                int p = st.back() * 2;
                res += p;
                st.push_back(p);
            } else if (s == "C") {
                int p = st.back();
                res -= p;
                st.pop_back();
            } else {
                int p = stoi(s);
                res += p;
                st.push_back(p);
            }
        }
        return res;
    }
};
// @lc code=end

