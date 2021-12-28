/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

// @lc code=start
class Solution {
 public:
  string toGoatLatin(string sentence) {
    stringstream ss;
    int index = 0;
    for (int l = 0, r = 0; r <= sentence.size(); ++r) {
      if (r == sentence.size() || sentence[r] == ' ') {
        string word = sentence.substr(l, r - l);
        word = convert(word, index);
        if (index != 0) ss << ' ';
        ss << word;
        ++index;
        l = r + 1;
      }
    }
    return ss.str();
  }

  string convert(string& s, int index) {
    stringstream ss;
    char fc = tolower(s[0]);
    if (fc == 'a' || fc == 'e' || fc == 'i' || fc == 'o' || fc == 'u') {
      ss << s << "ma";
    } else {
      ss << s.substr(1) << s[0] << "ma";
    }
    for (int i = 0; i <= index; ++i) {
      ss << 'a';
    }
    return ss.str();
  }
};
// @lc code=end
