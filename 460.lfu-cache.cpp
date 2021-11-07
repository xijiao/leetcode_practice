/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start
class LFUCache {
  struct Data {
    int value;
    int used;
    list<list<int>>::iterator it1;
    list<int>::iterator it2;
  };

  unordered_map<int, Data> M;
  list<list<int>> L;
  int cap;

 public:
  LFUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    auto mit = M.find(key);
    if (mit == M.end()) return -1;

    Data& data = mit->second;
    data.it1->erase(data.it2);
    data.used++;
    list<list<int>>::iterator newIt1 = next(data.it1);
    if (newIt1 == L.end() || M[newIt1->front()].used != data.used) {
      newIt1 = L.insert(newIt1, list<int>());
    }
    if (data.it1->empty()) L.erase(data.it1);
    data.it1 = newIt1;
    data.it1->push_back(key);
    data.it2 = prev(data.it1->end());
    return data.value;
  }

  void put(int key, int value) {
    if (cap == 0) return;

    auto mit = M.find(key);
    if (mit != M.end()) {
      mit->second.value = value;
      get(key);
      return;
    }

    if (M.size() >= cap) {
      auto it1 = L.begin();
      auto it2 = it1->begin();
      M.erase(*it2);
      it1->erase(it2);
      if (it1->empty()) {
        L.erase(it1);
      }
    }

    auto it1 = L.begin();
    if (it1 == L.end() || M[it1->front()].used != 1) {
      it1 = L.insert(it1, list<int>());
    }
    it1->push_back(key);
    auto it2 = prev(it1->end());
    M[key] = {value, 1, it1, it2};
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
