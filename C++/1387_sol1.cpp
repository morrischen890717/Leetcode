class Solution {
public:
    int solve(int num, unordered_map<int, int>& dp){
        if(dp.count(num) > 0)
            return dp[num];
        return dp[num] = (num % 2 ? solve(3 * num + 1, dp) : solve(num / 2, dp)) + 1;
    }
    int getKth(int lo, int hi, int k) {
        // using DP and unordered_map
        unordered_map<int, int> dp;
        dp[1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = lo; i <= hi; i++){
            pq.push({solve(i, dp), i});
        }
        for(int i = 1; i < k; i++){
            pq.pop();
        }
        return pq.top().second;
    }
};