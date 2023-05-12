class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        int ans = 0;
        int diff = nums[1] - nums[0];
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i - 1] == diff){
                cnt++;
            }
            else{
                diff = nums[i] - nums[i - 1];
                cnt = 0;
            }
            ans += cnt;
        }
        return ans;
    }
};