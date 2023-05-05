class Solution {
public:
    vector<int> origin;
    int n;
    Solution(vector<int>& nums) {
        origin = nums;
        n = origin.size();
        srand(time(NULL));
    }
    
    vector<int> reset() {
        return origin;
    }
    
    vector<int> shuffle() {
        vector<int> v(origin);
        // the code in the for loop is equal to std::random_shuffle() function
        int leftsize = n;
        for(int i = n - 1; i >= 0; i--){
            int j = rand() % n;
            swap(v[i], v[j]);
            leftsize--;
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */