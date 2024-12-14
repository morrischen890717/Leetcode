class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0;
        priority_queue<pair<int, int>> pq1;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            pq1.push({nums[r], r});
            pq2.push({nums[r], r});
            while(pq1.top().first - pq2.top().first > 2){
                l++;
                while(pq1.top().second < l){
                    pq1.pop();
                }
                while(pq2.top().second < l){
                    pq2.pop();
                }
            }
            ans += r - l + 1;
        }
        return ans;
    }
};