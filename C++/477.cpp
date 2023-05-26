class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < 32; i++){
            int bit = 1 << i;
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(nums[j] & bit)
                    cnt++;
            }
            sum += cnt * (n - cnt);
        }
        return sum;
    }
};