/*
 * @lc app=leetcode id=1178 lang=cpp
 *
 * [1178] Number of Valid Words for Each Puzzle
 */

// @lc code=start
class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<unordered_set<int>> wordset(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                wordset[i].insert(c);
            }
        }
        vector<int> res(puzzles.size());
        for (int i = 0; i < puzzles.size(); i++) {
            const string& puzzle = puzzles[i];
            // cout << puzzle << ": ";
            unordered_set<int> puzzlecount(puzzle.begin(), puzzle.end());
            for (int j = 0; j < words.size(); j++) {
                // cout << words[j] << ", ";
                if (!wordset[j].count(puzzle[0])) continue;
                bool failed = false;
                for (int c : wordset[j]) {
                    if (!puzzlecount.count(c)) {
                        failed = true;
                        break;
                    }
                }
                if (!failed) res[i]++;
            }
            // cout << endl;
        }
        return res;
    }
};
// @lc code=end

