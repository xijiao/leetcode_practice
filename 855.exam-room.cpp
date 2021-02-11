/*
 * @lc app=leetcode id=855 lang=cpp
 *
 * [855] Exam Room
 */

// @lc code=start
class ExamRoom {
    int N_;
    set<int> seats_;
public:
    ExamRoom(int N) : N_(N) {
        
    }
    
    int seat() {
        if (seats_.empty()) {
            seats_.insert(0);
            return 0;
        }
        int maxdis = 0;
        int index = 0;
        if (!seats_.count(0)) {
            maxdis = *seats_.begin();
            index = 0;
        }
        for (auto it = seats_.begin(); it != seats_.end() && next(it, 1) != seats_.end(); ++it) {
            int l = *(it);
            int r = *next(it, 1);
            if (r > l + 1 && (r - l) / 2 > maxdis) {
                maxdis = (r - l) / 2;
                index = l + (r - l) / 2;
            }
        }
        if (!seats_.count(N_ - 1) && N_ - 1 - *seats_.rbegin() > maxdis) {
            maxdis = N_ - 1 - *seats_.rbegin();
            index = N_ - 1;
        }

        seats_.insert(index);
        return index;
    }
    
    void leave(int p) {
        seats_.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
// @lc code=end

