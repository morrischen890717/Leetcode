class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // using sliding window
        // time complexity: O(N), space complexity: O(1)
        long long ans = 0;
        int n = nums.size();
        int max_num = *max_element(nums.begin(), nums.end()), cnt = 0, l = 0;
        for(int r = 0; r < n; r++){
            if(nums[r] == max_num)
                cnt++;
            while(l <= r && cnt >= k){
                if(nums[l] == max_num)
                    cnt--;
                l++;
            }
            ans += l;
        }
        return ans;
    }
};