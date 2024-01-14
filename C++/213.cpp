class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        int not_rob = 0, rob = 0;
        for(int i = start; i < end; i++){
            int not_rob_tmp = not_rob, rob_tmp = rob;
            not_rob = max(not_rob_tmp, rob_tmp);
            rob = not_rob_tmp + nums[i];
        }
        return max(not_rob, rob);
    }
    int rob(vector<int>& nums) {
        // using bottom-up DP
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/house-robber-ii/solutions/59934/simple-ac-solution-in-java-in-o-n-with-explanation/
        int n = nums.size();
        if(n == 1)
            return nums[0];
        return max(solve(nums, 0, n - 1), solve(nums, 1, n));
    }
};