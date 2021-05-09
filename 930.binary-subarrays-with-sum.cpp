/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        unordered_map<int, int> M{{0, 1}}; // key: sum - presum, value: count
        int res = 0, presum = 0;
        for (int a : A) {
            presum += a;
            res += M[S - presum];
            M[-presum]++;
        }
        return res;
    }

    // Accepted (24 ms)
    // int numSubarraysWithSum(vector<int>& A, int S) {
    //     if (A.empty()) return 0;
    //     int res = 0;
    //     if (S == 0) {
    //         int continiousZero = 0;
    //         for (int i = 0; ; i++) {
    //             if (i >= A.size() || A[i] == 1) {
    //                 res += (continiousZero + 1) * continiousZero / 2;
    //                 if (i >= A.size()) break;
    //                 continiousZero = 0;
    //             } else {
    //                 continiousZero++;
    //             }
    //         }
    //     } else {
    //         int l = 0, r = 0, sum = A[0];
    //         for (;;) {
    //             for (;r < A.size() - 1 && sum < S;) {
    //                 sum += A[++r];
    //             }
    //             if (sum < S) break;
    //             int l0count = 0, r0count = 0;
    //             for (;A[l] == 0; l++, l0count++);
    //             for (; r < A.size() - 1 && A[r + 1] == 0; r++, r0count++);
    //             res += (l0count + 1) * (r0count + 1);
    //             if (r == A.size() - 1) break;
    //             l++; r++;
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end

