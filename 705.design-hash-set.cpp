/*
 * @lc app=leetcode id=705 lang=cpp
 *
 * [705] Design HashSet
 */

// @lc code=start
class MyHashSet {
  vector<list<int>> data;
  int count = 0;

  void checkAndReallocte() {
    if (data.size() > count) return;

    vector<list<int>> olddata;
    olddata.swap(data);
    data.resize(max(1024, count * 2));
    count = 0;
    for (list<int>& l : olddata) {
      for (int v : l) _add(v);
    }
  }

  void _add(int v) {
    int h = hash(v);
    for (int n : data[h]) {
      if (n == v) return;
    }
    auto it = find(data[h].begin(), data[h].end(), v);
    if (it == data[h].end()) {
      data[h].push_back(v);
      count++;
    }
  }

  int hash(int v) { return (v * (long long)(1e9 + 7)) % data.size(); }

 public:
  MyHashSet() {}

  void add(int key) {
    checkAndReallocte();
    _add(key);
  }

  void remove(int key) {
    if (data.empty()) return;
    int h = hash(key);
    auto it = find(data[h].begin(), data[h].end(), key);
    if (it != data[h].end()) {
      data[h].erase(it);
      count--;
    }
  }

  bool contains(int key) {
    if (data.empty()) return false;
    int h = hash(key);
    auto it = find(data[h].begin(), data[h].end(), key);
    return it != data[h].end();
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
