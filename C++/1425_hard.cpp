class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // using monotonic deque
        // time complexity: O(N)
        int ans = INT_MIN;
        int n = nums.size();
        deque<pair<int, int>> q;
        for(int i = 1; i <= n; i++){
            int sum = q.empty() || q.front().second < 0 ? nums[i - 1] : nums[i - 1] + q.front().second;
            while(!q.empty() && sum > q.back().second){
                q.pop_back();
            }
            q.push_back({i, sum});
            ans = max(ans, q.front().second);
            if(i - q.front().first == k)
                q.pop_front();
        }
        return ans;
    }
};