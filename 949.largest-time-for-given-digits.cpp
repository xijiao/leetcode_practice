/*
 * @lc app=leetcode id=949 lang=cpp
 *
 * [949] Largest Time for Given Digits
 */

// @lc code=start
class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> cur;
        sort(arr.begin(), arr.end(), greater<int>());
        int used = 0;
        return helper(arr, cur, used);
    }

    string helper(vector<int>& arr, vector<int> cur, int used) {
        // for (int v : cur) {
        //     cout << v << " ";
        // }
        // cout << endl;
        if (cur.size() == 4) {
            if (isValid24h(cur)) return toClock(cur);
            else return "";
        }
        for (int i = 0; i < 4; i++) {
            if (used & (1 << i)) continue;
            if (cur.size() == 0 && arr[i] > 2) continue;
            if (cur.size() == 1 && cur[0] == 2 && arr[i] > 3) continue;
            if (cur.size() == 2 && arr[i] > 5) continue;
            cur.push_back(arr[i]);
            string res = helper(arr, cur, used | (1 << i));
            if (!res.empty()) return res;
            cur.pop_back();
        }
        return "";
    }

    bool isValid24h(const vector<int>& cur) {
        return (cur[0] * 10 + cur[1] < 24 && cur[2] * 10 + cur[3] < 60);
    }

    string toClock(const vector<int>& cur) {
        string res("00:00");
        res[0] += cur[0];
        res[1] += cur[1];
        res[3] += cur[2];
        res[4] += cur[3];
        return res;
    }
};
// @lc code=end

