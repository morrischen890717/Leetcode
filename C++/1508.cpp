class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // using priority_queue
        // time complexity: O(N^2 * logN), space complexity: O(N)
        // reference: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/solutions/730511/c-priority-queue-solution/?envType=daily-question&envId=2024-08-04
        const int MOD = 1e9 + 7;
        int ans = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        for(int i = 0; i < right; i++){
            pair<int, int> p = pq.top();
            pq.pop();
            if(i >= left - 1){
                ans += p.first;
                ans %= MOD;
            }
            if(p.second + 1 < n){
                p.second++;
                p.first += nums[p.second];
                pq.push(p);
            }
        }
        return ans;
    }
};