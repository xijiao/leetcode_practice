/*
 * @lc app=leetcode id=1483 lang=cpp
 *
 * [1483] Kth Ancestor of a Tree Node
 */

// @lc code=start
class TreeAncestor {
    vector<vector<int>> c2p;
public:
    TreeAncestor(int n, vector<int>& parent) {
        c2p.resize(20, vector<int>(parent.size(), -1));
        for (int node = 0; node < parent.size(); node++) {
            c2p[0][node] = parent[node];
        }

        for (int k = 1; k < 20; k++) {
            for (int node = 0; node < parent.size(); node++) {
                int nodep = c2p[k - 1][node];
                if (nodep != -1) {
                    c2p[k][node] = c2p[k - 1][nodep];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (int i = 0; i < 20; i++) {
            if ((1 << i) & k) {
                node = c2p[i][node];
                if (node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
// @lc code=end

