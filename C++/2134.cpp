class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // using sliding window
        // time complexity: O(N), space complexity: O(1)
        int ans = INT_MAX;
        int n = nums.size();
        int total = 0;
        for(int num: nums){
            if(num)
                total++;
        }
        int cnt = 0;
        for(int l = 0; l < n + total; l++){
            if(nums[l % n])
                cnt++;
            if(l >= total - 1){
                ans = min(ans, total - cnt);
                if(nums[(l - total + 1 + n) % n])
                    cnt--;
            }
        }
        return ans;
    }
};