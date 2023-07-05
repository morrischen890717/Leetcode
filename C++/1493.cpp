class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curCnt = 0, prevCnt = 0;
        for(int i = 0; i < n; i++){
            if(nums[i])
                curCnt++;
            else{
                ans = max(ans, curCnt + prevCnt);
                prevCnt = curCnt;
                curCnt = 0;   
            }
        }
        ans = max(ans, curCnt + prevCnt);
        return ans == n ? ans - 1 : ans; // we must delete one element, so if the elements in nums are all 1, then we should remove one 1 for answer
    }
};