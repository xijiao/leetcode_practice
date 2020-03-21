/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return construct(grid, 0, 0, n, n);
    }

    Node* construct(vector<vector<int>>& grid, int t, int l, int b, int r) {
        if (t == b || l == r) return nullptr;
        Node* node = new Node(grid[t][l], true);
        bool diff = false;
        for (int i = t; i < b; i++) {
            for (int j = l; j < r; j++) {
                if (grid[i][j] != node->val) {
                    diff = true;
                    break;
                }
            }
        }
        if (diff) {
            node->topLeft = construct(grid, t, l, (t + b) / 2, (l + r) / 2);
            node->topRight = construct(grid, t, (l + r) / 2, (t + b) / 2, r);
            node->bottomLeft = construct(grid, (t + b) / 2, l, b, (l + r) / 2);
            node->bottomRight = construct(grid, (t + b) / 2, (l + r) / 2, b, r);
            node->isLeaf = false;
        }
        return node;
    }

};
// @lc code=end

