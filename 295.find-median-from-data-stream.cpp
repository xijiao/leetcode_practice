/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
    priority_queue<int, vector<int>, greater<int>> BH;
    priority_queue<int> SH;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (BH.empty() || num > BH.top())
        {
            BH.push(num);
            if (BH.size() > SH.size() + 1)
            {
                SH.push(BH.top());
                BH.pop();
            }
        }
        else
        {
            SH.push(num);
            while (SH.size() > BH.size())
            {
                BH.push(SH.top());
                SH.pop();
            }
        }
    }

    double findMedian()
    {
        if (BH.size() > SH.size())
            return BH.top();
        else
            return (BH.top() + SH.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
