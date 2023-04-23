class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(), 1);
        if(cnt != 0)  // 1 has already existed in nums
            return n - cnt;
        int min_num = INT_MAX;
        int gcd_num;
        for(int i = 0; i < n; i++){
            gcd_num = nums[i];
            for(int j = i + 1; j < n; j++){
                gcd_num = gcd(gcd_num, nums[j]);
                if(gcd_num == 1){
                    min_num = min(min_num, (j - i) + (n - 1)); // (j-i) represents the steps to make one 1, (n-1) represents the steps to make the rest of the vector nums to be 1
                    break;
                }
            }
        }
        return (min_num == INT_MAX ? -1 : min_num);
    }
};