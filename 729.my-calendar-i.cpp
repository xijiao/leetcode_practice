/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class MyCalendar {
    map<int, int> R;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto it = R.lower_bound(start);
        if (it != R.end() && end > it->first) return false;
        cout << start << " " << end << endl;
        if (!R.empty() && it != R.begin()) {
            --it;
            if (it != R.end() && it->second > start) return false;
        }
        cout << start << " " << end << endl;
        R.emplace(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

