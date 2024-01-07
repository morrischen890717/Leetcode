class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // using Greedy and binary search
        // time complexity: O(NlogN), space complexity: O(N)
        int n = nums.size();
        vector<int> v = {INT_MAX};
        for(int num: nums){
            if(num > v.back())
                v.push_back(num);
            else{
                int pos = lower_bound(v.begin(), v.end(), num) - v.begin();
                v[pos] = num;
            }
        }
        return v.size();
    }
};