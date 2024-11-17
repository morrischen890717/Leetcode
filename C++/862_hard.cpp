class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        // using deque
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/solutions/143726/c-java-python-o-n-using-deque/?envType=daily-question&envId=2024-11-17
        int ans = INT_MAX;
        int n = nums.size();
        deque<int> q;
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for(int i = 0; i < n; i++){
            if(i > 0)
                prefix[i] = nums[i] + prefix[i - 1];
            if(prefix[i] >= k)
                ans = min(ans, i + 1);
            while(!q.empty() && prefix[i] - prefix[q.front()] >= k){
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while(!q.empty() && prefix[i] <= prefix[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};