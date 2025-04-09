class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int min_val = INT_MAX;
        unordered_set<int> s;
        for(int num: nums){
            s.insert(num);
            min_val = min(min_val, num);
        }
        if(k > min_val)
            return -1;
        return k == min_val ? s.size() - 1 : s.size();
    }
};