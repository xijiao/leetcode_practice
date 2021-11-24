/*
 * @lc app=leetcode id=187 lang=cpp
 *
 * [187] Repeated DNA Sequences
 */

// @lc code=start
class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> count;
    int x = 0;
    for (int i = 0; i < s.size(); i++) {
      x = (x << 2) | DNA2Bit(s[i]);
      if (i >= 9) {
        count[x]++;
        x &= ~(0x3 << 18);
      }
    }
    vector<string> ans;
    for (auto& node : count) {
      if (node.second < 2) continue;
      string v;
      for (int i = 0; i < 10; i++) {
        v.push_back(bit2DNA((node.first >> (i * 2)) & 0x3));
      }
      reverse(v.begin(), v.end());
      ans.push_back(v);
    }
    return ans;
  }

  int DNA2Bit(char dna) {
    switch (dna) {
      case 'A':
        return 0x0;
      case 'C':
        return 0x1;
      case 'G':
        return 0x2;
      case 'T':
        return 0x3;
    }
    return 0;
  }

  int bit2DNA(int bit) {
    static const char* DNA = "ACGT";
    return DNA[bit];
  }
};
// @lc code=end
