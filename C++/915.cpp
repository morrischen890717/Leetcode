class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/partition-array-into-disjoint-intervals/solutions/175945/java-one-pass-7-lines/
        int n = nums.size();
        int leftMax = nums[0], id = 0, curMax = leftMax;
        for(int i = 1; i < n; i++){
            if(leftMax > nums[i]){
                id = i;
                leftMax = curMax;
            }
            else
                curMax = max(curMax, nums[i]);
        }
        return id + 1;
    }
};