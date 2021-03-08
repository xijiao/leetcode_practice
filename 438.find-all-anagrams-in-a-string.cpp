/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> counts(26, 0), countp(26, 0);
        for (char c : p) {
            countp[c - 'a']++;
        }
        vector<int> res;
        for (int start = 0, i = 0; i < s.size(); i++) {
            char c = s[i];
            counts[c - 'a']++;
            while (counts[c - 'a'] > countp[c - 'a']) {
                counts[s[start] - 'a']--;
                start++;
            }
            if (i - start + 1 == p.size()) {
                res.push_back(start);
            }
        }
        return res;
    }
};
// @lc code=end

