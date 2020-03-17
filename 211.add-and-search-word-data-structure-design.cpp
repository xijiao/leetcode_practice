/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Add and Search Word - Data structure design
 */

// @lc code=start
class WordDictionary {
private:
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
        TrieNode() : isWord(false) {
            memset(children, 0, sizeof(children));            
        }

        TrieNode* getChild(char v) {
            return children[v - 'a'];
        };

        TrieNode* createChild(char v) {
            if (!children[v - 'a']) children[v - 'a'] = new TrieNode();
            return children[v - 'a'];
        };
    };
    TrieNode* root;

    bool search(const string& word, TrieNode* node, int index) {
        if (!node) return false;
        if (index == word.size()) return node->isWord;

        if (word[index] != '.') return search(word, node->getChild(word[index]), index + 1);
        else {
            for (char c = 'a'; c <= 'z'; c++) {
                if (search(word, node->getChild(c), index + 1)) return true;
            }
            return false;
        }
    }

public:
    /** Initialize your data structure here. */
    WordDictionary() : root(nullptr) {
        
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        if (word.empty()) return;
        if (!root) root = new TrieNode();
        TrieNode* cur = root;
        for (char c : word) {
            cur = cur->createChild(c);
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

