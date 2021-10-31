/*
 * @lc app=leetcode id=1825 lang=cpp
 *
 * [1825] Finding MK Average
 */

// @lc code=start
class MKAverage
{
    long long sum;
    int m;
    int k;
    int mk;
    deque<int> nums;
    multiset<int> left;
    multiset<int> mid;
    multiset<int> right;

    void _add(int num)
    {
        left.insert(num);

        if (left.size() > k)
        {
            int v = *left.rbegin();
            mid.insert(v);
            sum += v;
            left.erase(prev(left.end()));
        }

        if (mid.size() > mk)
        {
            int v = *mid.rbegin();
            right.insert(v);
            sum -= v;
            mid.erase(prev(mid.end()));
        }
    }

    void _del(int num)
    {
        multiset<int>::iterator it;
        if ((it = left.find(num)) != left.end())
        {
            left.erase(it);
        }
        else if ((it = mid.find(num)) != mid.end())
        {
            mid.erase(it);
            sum -= num;
        }
        else if ((it = right.find(num)) != right.end())
        {
            right.erase(it);
        }

        if (left.size() < k)
        {
            int v = *mid.begin();
            sum -= v;
            left.insert(v);
            mid.erase(mid.begin());
        }

        if (mid.size() < mk)
        {
            int v = *right.begin();
            sum += v;
            mid.insert(v);
            right.erase(right.begin());
        }
    }

public:
    MKAverage(int m, int k) : sum(0), m(m), k(k), mk(m - k * 2), nums()
    {
    }

    void addElement(int num)
    {
        if (nums.size() >= m)
        {
            _del(nums.front());
            nums.pop_front();
        }
        _add(num);
        nums.push_back(num);
    }

    int calculateMKAverage()
    {
        if (nums.size() == m)
        {
            return ((double)sum / (mk));
        }
        else
        {
            return -1;
        }
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
// @lc code=end
