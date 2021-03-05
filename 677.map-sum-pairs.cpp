/*
 * @lc app=leetcode id=677 lang=cpp
 *
 * [677] Map Sum Pairs
 */

// @lc code=start
class MapSum {
    struct TrieNode {
        int val = 0;
        TrieNode* children[26] = {nullptr};
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode* cur = root;
        for (char c : key) {
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            if (!cur->children[c - 'a']) {
                return 0;
            }
            cur = cur->children[c - 'a'];
        }
        queue<TrieNode*> q;
        q.push(cur);
        int res = 0;
        for (; !q.empty();) {
            cur = q.front();
            q.pop();
            res += cur->val;
            for (int i = 0; i < 26; i++) {
                if (cur->children[i]) q.push(cur->children[i]);
            }
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
// @lc code=end

