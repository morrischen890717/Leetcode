class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ans = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for(int i = 0; i < n; i++){
            if(i >= 2 && nums[i] < sum)
                ans = nums[i] + sum;
            sum += nums[i];
        }
        return ans;
    }
};