/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> res1, res2;
        for (const string& log : logs) {
            if (isDigitLog(log)) res2.push_back(log);
            else res1.push_back(convertStrLogForSort(log));
        }
        sort(res1.begin(), res1.end());
        for (string& log : res1) {
            log = convertStrLogForResult(log);
        }
        res1.insert(res1.end(), res2.begin(), res2.end());
        return res1;
    }

    bool isDigitLog(const string& log) {
        int index = log.find(' ');
        return (log[index + 1] >= '0' && log[index + 1] <= '9');
    }

    string convertStrLogForSort(const string& log) {
        int index = log.find(' ');
        string res = log.substr(index + 1) + "!" + log.substr(0, index);
        for (char& c : res) {
            if (c == ' ') c = '#';
        }
        return res;
    }

    string convertStrLogForResult(const string& log) {
        int index = log.rfind('!');
        string res = log.substr(index + 1) + " " + log.substr(0, index);
        for (char& c : res) {
            if (c == '#') c = ' ';
        }
        return res;
    }
};
// @lc code=end

