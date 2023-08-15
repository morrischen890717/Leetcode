class RLEIterator {
private:
    vector<int> v;
    int i = 0;
public:
    RLEIterator(vector<int>& encoding) {
        // time complexity: O(N), space complexity: O(1) (for extra space)
        v = encoding;
    }
    
    int next(int n) {
        while(i < v.size() && v[i] < n){
            n -= v[i];
            i += 2;
        }
        if(i >= v.size())
            return -1;
        v[i] -= n;
        return v[i + 1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */