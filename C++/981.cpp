class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
        return;
    }
    
    string get(string key, int timestamp) {
        int l = 0, r = m[key].size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(m[key][mid].first <= timestamp)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r < 0 ? "" : m[key][r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */