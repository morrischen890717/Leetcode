class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        bool increase = true;
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(increase){
                if(nums[i] > nums[i - 1])
                    cnt++;
                else{
                    ans = max(ans, cnt);
                    increase = false;
                    cnt = nums[i] == nums[i - 1] ? 0 : 1;
                }
            }
            else if(nums[i] < nums[i - 1])
                cnt++;
            else{
                ans = max(ans, cnt);
                increase = true;
                cnt = nums[i] == nums[i - 1] ? 0 : 1;
            }
        }
        ans = max(ans, cnt);
        return ans + 1;
    }
};