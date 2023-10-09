class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // using sliding window and two-pointers
        // time complexity: O(N), space complexity: O(1)
        int n = nums.size();
        int ans = 0, cnt = 0;
        int l = 0;
        int rightmost = -1;
        for(int r = 0; r < n; r++){
            if(nums[r] % 2){
                cnt++;
            }
            int left_cnt = 0;
            while(cnt > k){
                if(nums[l] % 2)
                    cnt--;
                l++;
                left_cnt++;
            }
            ans += left_cnt * (r - rightmost);
            if(nums[r] % 2)
                rightmost = r;
        }
        int left_cnt = 0;
        while(cnt == k){
            if(nums[l] % 2)
                cnt--;
            l++;
            left_cnt++;
        }
        ans += left_cnt * (n - rightmost);
        return ans;
    }
};