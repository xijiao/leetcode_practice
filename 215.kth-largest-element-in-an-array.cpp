/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution
{
public:
    // N*logk
    // int findKthLargest(vector<int> &nums, int k)
    // {
    //     priority_queue<int, vector<int>, greater<int>> P;
    //     for (int n : nums)
    //     {
    //         P.push(n);
    //         if (P.size() > k)
    //         {
    //             P.pop();
    //         }
    //     }
    //     return P.top();
    // }

    int findKthLargest(vector<int> &nums, int k)
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(nums.begin(), nums.end(), std::default_random_engine(seed));
        int n = nums.size();
        k = n - k;

        int l = 0, r = n - 1;
        while (l < r)
        {
            // for (int n : nums)
            // {
            //     cout << n << " ";
            // }
            // cout << endl;

            int m = partition(nums, l, r);
            // for (int n : nums)
            // {
            //     cout << n << " ";
            // }
            // cout << endl;
            // cout << l << " " << r << " " << m << endl;
            if (m == k)
            {
                break;
            }
            else if (m < k)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }

        return nums[k];
    }

    int partition(vector<int> &nums, int l, int r)
    {
        int i = l + 1, j = r;
        for (;;)
        {
            for (; i <= r && nums[i] <= nums[l]; i++)
                ;
            for (; j > l && nums[j] >= nums[l]; j--)
                ;
            if (i >= j)
                break;

            swap(nums[i++], nums[j--]);
        }
        swap(nums[l], nums[j]);
        return j;
    }
};
// @lc code=end
