class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        for(int num: nums){
            sum += num;
        }
        long long left = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            left += nums[i];
            if(left >= sum - left)
                ans++;
        }
        return ans;
    }
};