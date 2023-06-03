class Solution {
public:
    int sum;
    vector<int> prefix; // prefix sum
    Solution(vector<int>& w) {
        prefix = vector<int> (w.size());
        sum = 0;
        for(int i = 0; i < w.size(); i++){
            sum += w[i];
            prefix[i] = sum;
        }
        srand(time(NULL));
    }
    
    int pickIndex() {
        int pick = rand() % sum + 1;
        auto it = lower_bound(prefix.begin(), prefix.end(), pick);
        return it - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */