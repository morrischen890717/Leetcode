class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // using two-pointers, sliding window
        // time complexity: O(N), space complexity: O(1)
        int ans = 0;
        int n = nums.size();
        int l = 0, cnt = 0;
        for(int r = 0; r < n; r++){
            if(nums[r])
                cnt++;
            else if(k > 0){
                k--;
                cnt++;
            }
            else{
                ans = max(ans, cnt);
                while(nums[l]){
                    l++;
                    cnt--;
                }
                l++;
            }
        }
        ans = max(ans, cnt);
        return ans;
    }
};