class Solution {
public:
    int solve(vector<int>& nums, int i, int cur){
        if(i == nums.size())
            return cur;
        return solve(nums, i + 1, cur) + solve(nums, i + 1, cur ^ nums[i]);
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(nums, 0, 0);
    }
};