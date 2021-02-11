/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        unordered_map<string, int> map_words;
        for (const string& word : words) {
            map_words[word]++;
        }
        int wl = words[0].size();
        int wc = words.size();
        for (int i = 0; i < wl; i++) {
            match(res, s, map_words, i, wc);
        }
        return res;
    }

    void match(vector<int>& res, const string& s, unordered_map<string, int> map_words, int start, int wordcount) {
        unordered_map<string, int> l_map_words;
        int wordlength = map_words.begin()->first.size();
        int l_wordcount = 0;
        int cur_index = start;
        while (cur_index + (wordcount - l_wordcount) * wordlength <= s.size()) {
            string cur = s.substr(cur_index, wordlength);
            l_map_words[cur] ++;
            l_wordcount++;
            if (l_map_words[cur] > map_words[cur]) {
                while (l_map_words[cur] > map_words[cur]) {
                    string start_str = s.substr(start, wordlength);
                    l_map_words[start_str]--;
                    l_wordcount--;
                    start += wordlength;
                }
            } else if (l_wordcount == wordcount) {
                res.push_back(start);

                string start_str = s.substr(start, wordlength);
                l_map_words[start_str]--;
                l_wordcount--;
                start += wordlength;
            }
            cur_index += wordlength;
        }
    }
};
// @lc code=end

