/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<int> N;
        stack<string> S;
        stringstream si(s);
        stringstream cur;
        int num = 0;
        bool lookingNumber = true;
        char v;
        while (si.get(v)) {
            //cout << "v=" << v << endl;
            if (v >= '0' && v <= '9') {
                if (lookingNumber) {
                    num *= 10;
                    num += (v - '0');
                } else {
                    N.push(num);
                    S.push(cur.str());
                    num = v - '0';
                    cur.str("");
                    lookingNumber = true;
                }
            } else if (v == '[') {
                lookingNumber = false;
            } else if (v == ']') {
                stringstream ncur;
                if (!S.empty()) {
                    ncur.str(S.top());
                    ncur.seekp(0, ios_base::end);
                    S.pop();
                }
                for (int i = 0; i < num; i++) {
                    ncur << cur.str();
                }
                num = 0;
                if (!N.empty()) {
                    num = N.top();
                    N.pop();
                }
                //cout << ncur.str() << endl;
                cur.swap(ncur);
            } else {
                cur << v;
                lookingNumber = false;
            }
        }
        return cur.str();
    }
};
// @lc code=end

