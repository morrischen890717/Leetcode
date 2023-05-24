class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        /*
        time complexity: O(NlogN), space somplexity: O(N)
        reference: https://leetcode.com/problems/maximum-subsequence-score/solutions/3082106/java-c-python-priority-queue/
        */
        int n = nums1.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<pair<int, int>> nums(n);
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++){
            nums[i] = {nums2[i], nums1[i]};
        }
        sort(nums.begin(), nums.end(), greater<pair<int, int>>());
        for(pair<int, int> p: nums){
            pq.push(p.second);
            sum += p.second;
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k)
                ans = max(ans, sum * p.first);
        }
        return ans;
    }
};