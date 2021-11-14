/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
class Solution {
 public:
  // Accepted
  // 112/112 cases passed (420 ms)
  // Your runtime beats 8.69 % of cpp submissions
  // Your memory usage beats 13.45 % of cpp submissions (65 MB)
  // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
  //   int n = graph.size();
  //   unordered_set<int> safeNodes;
  //   vector<vector<int>> regraph(n);
  //   for (int i = 0; i < n; i++) {
  //     for (int dest : graph[i]) {
  //       regraph[dest].push_back(i);
  //     }
  //   }
  //   queue<int> Q;
  //   for (int i = 0; i < n; i++) {
  //     Q.push(i);
  //   }
  //   while (!Q.empty()) {
  //     int cur = Q.front();
  //     Q.pop();
  //     if (safeNodes.count(cur)) continue;
  //     int safe = true;
  //     for (int dest : graph[cur]) {
  //       // if (dest == cur) continue;
  //       if (safeNodes.count(dest)) continue;
  //       safe = false;
  //       break;
  //     }
  //     if (!safe) continue;
  //     safeNodes.insert(cur);
  //     for (int prev : regraph[cur]) {
  //       if (!safeNodes.count(prev)) {
  //         Q.push(prev);
  //       }
  //     }
  //   }
  //   vector<int> res(safeNodes.begin(), safeNodes.end());
  //   sort(res.begin(), res.end());
  //   return res;
  // }
  unordered_set<int> safeNodes;
  unordered_set<int> unsafeNodes;
  unordered_set<int> visitedNodes;

  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> res;
    for (int i = 0; i < graph.size(); i++) {
      if (dfs(graph, i)) {
        res.push_back(i);
      }
    }
    return res;
  }

  bool dfs(vector<vector<int>>& graph, int node) {
    if (safeNodes.count(node)) return true;
    if (unsafeNodes.count(node)) return false;
    if (visitedNodes.count(node)) {
      unsafeNodes.insert(node);
      return false;
    }
    visitedNodes.insert(node);

    bool res = true;
    for (int next : graph[node]) {
      if (!dfs(graph, next)) {
        res = false;
        break;
      }
    }
    if (res) {
      safeNodes.insert(node);
    } else {
      unsafeNodes.insert(node);
    }
    return res;
  }
};
// @lc code=end
