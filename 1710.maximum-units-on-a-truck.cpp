/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    // int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    //     sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
    //         if (a[1] == b[1]) return a[0] > b[0];
    //         else return a[1] > b[1]; 
    //     });
    //     int res = 0;
    //     for (vector<int>& box : boxTypes) {
    //         int num = min(box[0], truckSize);
    //         res += num * box[1];
    //         truckSize -= num;
    //         if (truckSize == 0) break;
    //     }
    //     return res;
    // }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int unit2count[1001] = {0};
        for (vector<int>& box : boxTypes) {
            unit2count[box[1]] += box[0];
        }
        int res = 0;
        for (int i = 1000; i >= 0; i--) {
            int num = min(unit2count[i], truckSize);
            res += num * i;
            truckSize -= num;
            if (truckSize == 0) break;
        }
        return res;
    }
};
// @lc code=end

