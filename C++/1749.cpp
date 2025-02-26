class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        int max_sum = 0, min_sum = 0;
        for(int num: nums){
            sum += num;
            ans = max({ans, abs(sum - min_sum), abs(sum - max_sum)});
            max_sum = max(max_sum, sum);
            min_sum = min(min_sum, sum);
        }
        return ans;
    }
};