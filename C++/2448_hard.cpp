class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        /*
        Time Complexity: O(NlogN), Space Complexity: O(N)
        main idea: image that the number of each nums[i] is cost[i], and compute the median of them. 
        (
        e.g. nums = {7, 2, 3}, cost = {3, 5, 1}, the new vector should be [2, 2, 2, 2, 2, 3, 7, 7, 7], the median would be 2, so we should let all element to be 2 with their costs
        (equals to let each element in new vector to be 2 with the cost = 1,
        nums[i] add 1 with cost[i] equals to cost[i] of nums[i] add 1 with cost = 1)
        )
        The answer is the sum of the costs which make each nums[i] to median

        Reference:
        https://leetcode.com/problems/minimum-cost-to-make-array-equal/solutions/2734183/python3-weighted-median-o-nlogn-with-explanations/
        LC 462. Minimum Moves to Equal Array Elements II: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
        */
        int n = nums.size();
        vector<pair<int, int>> v(n); // {nums, cost}
        long long totalCost = 0;
        for(int i = 0; i < n; i++){
            v[i] = {nums[i], cost[i]};
            totalCost += cost[i];
        }
        sort(v.begin(), v.end());
        long long target = totalCost / 2 + 1; // get the target-th element(median) in new vector, +1  is because of the odd number
        long long cnt = 0;
        int median;
        // get median
        for(int i = 0; i < n; i++){
            cnt += v[i].second;
            if(cnt >= target){
                median = v[i].first;
                break;
            }
        }
        long long ans = 0;
        for(int i = 0; i < n; i++){
            ans += ((long long)abs(median - v[i].first) * v[i].second);
        }
        return ans;
    }
};