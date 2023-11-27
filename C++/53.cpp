class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = 0;
        for(int& num: nums){
            sum = max(0, sum) + num;
            ans = max(ans, sum);
        }
        return ans;
    }
};