class RandomizedSet {
private:
    unordered_map<int, int> m; // {val, id in nums}
    vector<int> nums;
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if(m.count(val))
            return false;
        m[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val))
            return false;
        int end = nums.back();
        m[end] = m[val];
        nums[m[val]] = end;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int pos = rand() % nums.size();
        return nums[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */