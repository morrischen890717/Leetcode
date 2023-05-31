class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> in;
    unordered_map<string, pair<double, int>> travel;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
        return;
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> p = in[id];
        in.erase(id);
        string route = p.first + "_" + stationName;
        travel[route].first += t - p.second;
        travel[route].second++;
        return;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        return travel[route].first / travel[route].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */