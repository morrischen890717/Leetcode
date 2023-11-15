class Solution {
public:
    int solve(int num, unordered_map<int, int>& dp){
        if(dp.count(num) > 0)
            return dp[num];
        return dp[num] = (num % 2 ? solve(3 * num + 1, dp) : solve(num / 2, dp)) + 1;
    }
    int getKth(int lo, int hi, int k) {
        // using DP, unordered_map, and nth_element
        unordered_map<int, int> dp;
        dp[1] = 0;
        vector<pair<int, int>> v;
        for(int i = lo; i <= hi; i++){
            v.push_back({solve(i, dp), i});
        }
        nth_element(v.begin(), v.begin() + k - 1, v.end());
        return v[k - 1].second;
    }
};