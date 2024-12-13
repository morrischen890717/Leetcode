class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int cnt = 0;
        vector<bool> chosen(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++){
            pq.push({nums[i], i});
        }
        while(cnt < n){
            pair<int, int> p = pq.top();
            pq.pop();
            if(chosen[p.second])
                continue;
            ans += p.first;
            for(int k = -1; k <= 1; k++){
                int id = p.second + k;
                if(id >= 0 && id < n && !chosen[id]){
                    chosen[id] = true;
                    cnt++;
                }
            }
        }
        return ans;
    }
};