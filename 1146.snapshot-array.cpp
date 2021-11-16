/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
  vector<map<int, int>> data;
  int cur_snap_id;

 public:
  SnapshotArray(int length) : data(length), cur_snap_id(0) {}

  void set(int index, int val) { data[index][cur_snap_id] = val; }

  int snap() { return cur_snap_id++; }

  int get(int index, int snap_id) {
    auto it = data[index].upper_bound(snap_id);
    if (it == data[index].begin()) return 0;
    --it;
    return it->second;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end
