/*
 * @lc app=leetcode id=1286 lang=cpp
 *
 * [1286] Iterator for Combination
 */

// @lc code=start
class CombinationIterator {
  string C;
  unordered_map<int, int> CMap;
  string cur;
  string last;
public:
  CombinationIterator(string characters, int combinationLength) {
    C = characters;
    for (int i = 0; i < C.size(); i++) {
      CMap[C[i]] = i;
    }
    last = C.substr(C.size() - combinationLength, combinationLength);
  }
  
  string next() {
    if (cur.empty()) {
      cur = C.substr(0, last.size());
      return cur;
    }
    for (int i = cur.size() - 1; i >= 0; --i) {
      char c = cur[i];
      int index = CMap[c];
      if (C.size() - index <= cur.size() - i) continue;
      for (int j = i; j < cur.size(); j++) {
        cur[j] = C[++index];
      }
      break;
    }
    return cur;
  }
  
  bool hasNext() {
    return cur != last;
  }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

