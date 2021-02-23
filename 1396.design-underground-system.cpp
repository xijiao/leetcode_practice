/*
 * @lc app=leetcode id=1396 lang=cpp
 *
 * [1396] Design Underground System
 */

// @lc code=start
class UndergroundSystem {
    unordered_map<int, pair<string, int>> from; // id -> (from, starttime)
    unordered_map<string, pair<int, int>> statics; // (from, to) -> (sum, count)
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        from.insert({id, {stationName, t}});
    }
    
    void checkOut(int id, string stationName, int t) {
        const auto& fromdata = from[id];
        auto& sdata = statics[fromdata.first + "->" + stationName];
        sdata.first += (t - fromdata.second);
        sdata.second++;
        from.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        const auto& sdata = statics[startStation + "->" + endStation];
        if (sdata.second == 0) return 0; 
        return (double)sdata.first / sdata.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
// @lc code=end

