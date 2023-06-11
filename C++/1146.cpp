class SnapshotArray {
public:
    vector<vector<pair<int, int>>> v; 
    int snap_id;
    SnapshotArray(int length) {
        snap_id = 0;
        v = vector<vector<pair<int, int>>> (length); // v[index][...] = {snap_id(version), val} 
        for(int i = 0; i < length; i++){
            v[i].push_back({snap_id, 0});
        }
    }
    
    void set(int index, int val) {
        pair<int, int> p = v[index].back();
        if(p.first == snap_id)
            v[index].back().second = val;
        else
            v[index].push_back({snap_id, val});
        return;
    }
    
    int snap() {
        snap_id++;
        return snap_id - 1;
    }
    
    int get(int index, int snap_id) {
        int l = 0, r = v[index].size() - 1;
        while(l <= r){ // binary search for version
            int mid = l + (r - l) / 2;
            pair<int, int> p = v[index][mid];
            if(p.first == snap_id)
                return p.second;
            else if(p.first < snap_id)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return v[index][r].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */