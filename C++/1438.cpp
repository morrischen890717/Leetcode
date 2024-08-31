class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // using priority_queue
        // time complexity: O(NlogN), space complexity: O(N)
        int ans = 0;
        int n = nums.size();
        priority_queue<pair<int, int>> max_pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_pq;
        int l = -1;
        for(int r = 0; r < n; r++){
            while(!max_pq.empty() && max_pq.top().first > nums[r] + limit){
                l = max(l, max_pq.top().second);
                max_pq.pop();
            }
            while(!min_pq.empty() && min_pq.top().first < nums[r] - limit){
                l = max(l, min_pq.top().second);
                min_pq.pop();
            }
            ans = max(ans, r - l);
            max_pq.push({nums[r], r});
            min_pq.push({nums[r], r});
        }
        return ans;
    }
};