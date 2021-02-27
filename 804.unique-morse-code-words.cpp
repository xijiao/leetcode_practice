/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

// @lc code=start
class Solution {
    static constexpr char* morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> res;
        for (const string& word : words) {
            stringstream ss;
            for (char c : word) {
                ss << morse[c - 'a'];
            }
            res.insert(ss.str());
        }
        return res.size();
    }
};
// @lc code=end

