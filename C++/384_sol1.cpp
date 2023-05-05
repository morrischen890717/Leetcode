class Solution {
public:
    vector<int> origin;
    Solution(vector<int>& nums) {
        origin = nums;
        srand(time(NULL));
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> v(origin);
        random_shuffle(v.begin(), v.end());
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */