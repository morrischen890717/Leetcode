class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int ans = 0;
        int sum = 0, l = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(l <= i && sum > goal){
                sum -= nums[l];
                l++;
            }
            ans += i - l + 1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // using two-pointers and sliding window
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/binary-subarrays-with-sum/solutions/186683/c-java-python-sliding-window-o-1-space/
        return solve(nums, goal) - solve(nums, goal - 1);
    }
};