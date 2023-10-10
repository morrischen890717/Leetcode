class Solution {
public:
    int minOperations(vector<int>& nums) {
        // using sort() and sliding window
        // reference: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/solutions/1470857/c-sliding-window/?envType=daily-question&envId=2023-10-10
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
        int ans = n;
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            while(j < nums.size() && nums[j] < nums[i] + n){
                j++;
            }
            ans = min(ans, n - j + i);
        }   
        return ans;
    }
};