class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; i++){
            int diff = nums[i + 1] - nums[i];
            int j = i + 2;
            while(j < n && nums[j] - nums[j - 1] == diff){
                cnt++;
                j++;
            }
        }
        return cnt;
    }
};