class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        for(int i = 0; i < k; i++){
            int cur = pq.top();
            pq.pop();
            ans += cur;
            pq.push(cur / 3 + (cur % 3 ? 1 : 0));
        }
        return ans;
    }
};