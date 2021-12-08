/*
 * @lc app=leetcode id=706 lang=cpp
 *
 * [706] Design HashMap
 */

// @lc code=start
class MyHashMap {
  vector<list<pair<int, int>>> data;
  int count = 0;

  void checkAndIncreaseCapacity() {
    if (count < data.size()) return;

    vector<list<pair<int, int>>> olddata;
    olddata.swap(data);

    data.resize(max(1024, count * 2));
    count = 0;
    for (list<pair<int, int>>& l : olddata) {
      for (pair<int, int>& p : l) {
        _put(p.first, p.second);
      }
    }
  }

  void _put(int key, int value) {
    int h = hash(key);
    auto it =
        find_if(data[h].begin(), data[h].end(),
                [&key](const pair<int, int>& p) { return p.first == key; });
    if (it == data[h].end()) {
      data[h].push_back({key, value});
      count++;
    } else {
      it->second = value;
    }
  }

  int hash(int key) { return ((long long)key * 100000007) % data.size(); }

 public:
  MyHashMap() {}

  void put(int key, int value) {
    checkAndIncreaseCapacity();
    _put(key, value);
  }

  int get(int key) {
    if (data.empty()) return -1;
    int h = hash(key);
    auto it =
        find_if(data[h].begin(), data[h].end(),
                [&key](const pair<int, int>& p) { return p.first == key; });
    if (it == data[h].end()) {
      return -1;
    } else {
      return it->second;
    }
  }

  void remove(int key) {
    if (data.empty()) return;
    int h = hash(key);
    auto it =
        find_if(data[h].begin(), data[h].end(),
                [&key](const pair<int, int>& p) { return p.first == key; });
    if (it != data[h].end()) {
      data[h].erase(it);
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
