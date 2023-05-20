class Solution {
public:
    int minMoves(vector<int>& nums) {
        // reference: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/solutions/93817/it-is-a-math-question/
        int n = nums.size();
        int sum = 0;
        int minNum = INT_MAX;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            minNum = min(minNum, nums[i]);
        }
        return sum - minNum * n;
    }
};