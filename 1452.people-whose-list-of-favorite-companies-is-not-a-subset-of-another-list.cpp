/*
 * @lc app=leetcode id=1452 lang=cpp
 *
 * [1452] People Whose List of Favorite Companies Is Not a Subset of Another List
 */

// @lc code=start
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string, int> index;
        vector<bitset<50000>> bitlist(favoriteCompanies.size());
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            auto& people = favoriteCompanies[i];
            for (auto& company : people) {
                if (index.count(company) == 0) {
                    index[company] = index.size();
                }
                bitlist[i].set(index[company]);
            }
        }
        vector<int> res;
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            bool is_subset = false;
            for (int j = 0; j < favoriteCompanies.size(); j++) {
                if (i == j) continue;
                if ((bitlist[i] & bitlist[j]) == bitlist[i]) {
                    is_subset = true;
                    break;
                }
            }
            if (!is_subset) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

