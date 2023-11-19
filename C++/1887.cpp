class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        // using sort
        // time complexity: O(NlogN), space complexity: O(1)
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1])
                ans += n - i;
        }
        return ans;
    }
};