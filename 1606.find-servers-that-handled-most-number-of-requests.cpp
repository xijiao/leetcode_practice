/*
 * @lc app=leetcode id=1606 lang=cpp
 *
 * [1606] Find Servers That Handled Most Number of Requests
 */

// @lc code=start
class Solution {
 public:
  vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    priority_queue<vector<int>, vector<vector<int>>, greater<>> busyServers;
    set<int> available;
    unordered_map<int, int> count;
    for (int i = 0; i < k; i++) {
      available.insert(i);
    }

    for (int i = 0; i < arrival.size(); i++) {
      while (!busyServers.empty() && busyServers.top()[0] <= arrival[i]) {
        available.insert(busyServers.top()[1]);
        busyServers.pop();
      }
      if (available.empty()) continue;

      auto it = available.lower_bound(i % k);
      if (it == available.end()) {
        it = available.begin();
      }
      // cout << "<==" << *it << " " << arrival[i] + load[i] << endl;
      busyServers.push({arrival[i] + load[i], *it});
      count[*it]++;
      available.erase(it);
    }

    int maxCount = 0;
    vector<int> res;
    for (auto c : count) {
      // cout << c.first << " " << c.second << endl;
      if (c.second > maxCount) {
        res.clear();
        res.push_back(c.first);
        maxCount = c.second;
      } else if (c.second == maxCount) {
        res.push_back(c.first);
      }
    }
    return res;
  }
};
// @lc code=end
