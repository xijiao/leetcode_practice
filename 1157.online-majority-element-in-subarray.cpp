/*
 * @lc app=leetcode id=1157 lang=cpp
 *
 * [1157] Online Majority Element In Subarray
 */

// @lc code=start
class MajorityChecker {
private:
    unordered_map<int, vector<int>> idx;
public:
    MajorityChecker(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            idx[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        for (const auto& p : idx) {
            if (p.second.size() < threshold) continue;
            auto it1 = lower_bound(p.second.begin(), p.second.end(), left);
            auto it2 = upper_bound(p.second.begin(), p.second.end(), right);
            if (it2 - it1 < threshold) continue;
            return p.first;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
// @lc code=end

