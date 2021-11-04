/*
 * @lc app=leetcode id=1797 lang=cpp
 *
 * [1797] Design Authentication Manager
 */

// @lc code=start
class AuthenticationManager {
  struct Token {
    int expireTime;
    list<string>::iterator it;
  };
  int _timeToLive;
  unordered_map<string, Token> _tokens;
  list<string> _list;

  void refresh(int currentTime) {
    for (;;) {
      if (_list.empty()) break;
      Token& token = _tokens[_list.front()];
      if (token.expireTime > currentTime) break;
      _tokens.erase(_list.front());
      _list.pop_front();
    }
  }

 public:
  AuthenticationManager(int timeToLive) : _timeToLive(timeToLive) {}

  void generate(string tokenId, int currentTime) {
    refresh(currentTime);
    _list.push_back(tokenId);
    _tokens[tokenId] = {currentTime + _timeToLive, prev(_list.end())};
  }

  void renew(string tokenId, int currentTime) {
    refresh(currentTime);
    if (!_tokens.count(tokenId)) return;
    Token& token = _tokens[tokenId];
    _list.erase(token.it);
    _list.push_back(tokenId);
    token.it = prev(_list.end());
    token.expireTime = currentTime + _timeToLive;
  }

  int countUnexpiredTokens(int currentTime) {
    refresh(currentTime);
    return _tokens.size();
  }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
// @lc code=end
