class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // using Greedy
        // reference: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/solutions/4811460/greedy-sacrifice/?envType=daily-question&envId=2024-05-19
        long long sum = 0;
        int cnt = 0, drop = INT_MAX;
        for(int num: nums){
            sum += max(num, num ^ k);
            cnt += (num ^ k) > num;
            drop = min(drop, abs(num - (num ^ k)));
        }
        return cnt % 2 ? sum - drop : sum;
    }
};