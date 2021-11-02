/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */

// @lc code=start
class Solution
{
public:
    // top down
    // int numberOfArrays(string s, int k)
    // {
    //     int MOD = 1e9 + 7;
    //     int n = s.size();
    //     vector<int> dp(n + 1, 0);
    //     dp[0] = 1;

    //     int consecutive_zeros = 0;
    //     for (int i = 1; i <= n; ++i)
    //     {
    //         int value = 0;
    //         for (int j = i - 1; j >= 0; --j)
    //         {
    //             if (s[j] == '0')
    //             {
    //                 continue;
    //             }
    //             if (i - j > 10 || (i - j == 10 && s[j] > '1'))
    //                 break;
    //             int v = stoi(s.substr(j, i - j));
    //             if (v > k)
    //                 break;
    //             dp[i] = (dp[i] + dp[j]) % MOD;
    //         }
    //         if (dp[i] == 0)
    //             consecutive_zeros++;
    //         else
    //             consecutive_zeros = 0;
    //         if (consecutive_zeros > 10)
    //             return 0;
    //     }
    //     return dp[n];
    // }

    // bottom up
    int numberOfArrays(string s, int k)
    {
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; ++i)
        {
            long long value = 0;
            if (s[i - 1] == '0')
                continue;
            for (int j = i; j <= n; ++j)
            {
                value = value * 10 + (s[j - 1] - '0');
                if (value > k)
                    break;
                dp[j] = (dp[j] + dp[i - 1]) % MOD;
            }
        }

        return dp[n];
    }
};
// @lc code=end
