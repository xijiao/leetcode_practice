/*
 * @lc app=leetcode id=715 lang=cpp
 *
 * [715] Range Module
 */

// @lc code=start
class RangeModule {
    map<int, int> ranges; // left -> right
public:
    RangeModule() {
        
    }
    
    void addRange(int left, int right) {
        auto itl = ranges.upper_bound(left);
        if (itl != ranges.begin()) {
            --itl;
            if (itl->second < left) ++itl;
        }
        auto itr = ranges.upper_bound(right);
        if (itl != itr) {
            left = min(left, itl->first);
            --itr;
            right = max(right, itr->second);
            ++itr;
            ranges.erase(itl, itr);
        }
        ranges[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto itl = ranges.upper_bound(left);
        if (itl == ranges.begin() || (--itl)->second < right) return false;
        return true;        
    }
    
    void removeRange(int left, int right) {
        auto itl = ranges.upper_bound(left);
        if (itl != ranges.begin()) {
            --itl;
            if (itl->second < left) ++itl;
        }
        auto itr = ranges.upper_bound(right);
        if (itl == itr) return;
        --itr;
        int moreleft = min(left, itl->first), moreright = max(right, itr->second);
        ++itr;
        ranges.erase(itl, itr);
        if (moreleft != left) ranges[moreleft] = left;
        if (moreright != right) ranges[right] = moreright;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
// @lc code=end

