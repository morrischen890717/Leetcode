class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        for(int i = 0; i < k; i++){
            pair<int, int> p = pq.top();
            pq.pop();
            p.first = nums[p.second] *= multiplier;
            pq.push(p);
        }
        return nums;
    }
};