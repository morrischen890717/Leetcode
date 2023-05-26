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
            sum += cnt * (n - cnt); // cnt: # of num which is 1 in i-th bit, (n-cnt): # of num which is 0 in i-th bit
        }
        return sum;
    }
};