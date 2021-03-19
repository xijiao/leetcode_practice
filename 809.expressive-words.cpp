/*
 * @lc app=leetcode id=809 lang=cpp
 *
 * [809] Expressive Words
 */

// @lc code=start
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int res = words.size();
        for (const auto& word : words) {
            for (int i = 0, j = 0; i < S.size() || j < word.size(); ) {
                if (i < S.size() && j < word.size() && S[i] == word[j]) {
                    i++;
                    j++;
                    continue;
                }
                if (i == 0 || i >= S.size()) {
                    res--;
                    break;
                }
                if (S[i - 1] != S[i] ||
                        !(
                            (i > 1 && S[i - 2] == S[i - 1]) ||
                            (i < S.size() - 1 && S[i] == S[i + 1])
                        )
                    ) {
                    res--;
                    break;
                }
                while (i < S.size() && S[i - 1] == S[i]) i++;
            }
        }
        return res;
    }
};
// @lc code=end

