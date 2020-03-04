/*
 * @lc app=leetcode id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        if (arr.size() <= 1) return 1;
        multiset<int> ranges = {arr[0], arr[0]};
        for (int i = 1; i < arr.size(); i++) {
            int v = arr[i];
            auto it = ranges.upper_bound(v);
            if (it == ranges.end()) {
                ranges.insert(v);
                ranges.insert(v);
            } else {
                for (auto former = it++; it != ranges.end(); former = it++) {
                    ranges.erase(former);
                }
                if (ranges.size() % 2 == 1) {
                    ranges.insert(v);
                }
            }
        }
        return ranges.size() / 2;
    }
};
// @lc code=end

