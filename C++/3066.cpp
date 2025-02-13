class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        while(!pq.empty() && pq.top() < k){
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();
            pq.push((long long)min(num1, num2) * 2 + max(num1, num2));
            ans++;
        }
        return ans;
    }
};