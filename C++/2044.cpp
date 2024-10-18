class Solution {
public:
    int solve(vector<int>& nums, int i, int cur, int target){
        if(i == nums.size())
            return cur == target ? 1 : 0;
        return solve(nums, i + 1, cur, target) + solve(nums, i + 1, cur | nums[i], target);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int num: nums){
            target |= num;
        }
        return solve(nums, 0, 0, target);
    }
};