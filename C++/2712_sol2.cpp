class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        vector<vector<long long>> prefix(n + 2, vector<long long> (2, 0));
        vector<vector<long long>> suffix(n + 2, vector<long long> (2, 0));
        int num;
        for(int i = 1; i <= n; i++){
            num = s[i - 1] - '0';
            prefix[i][num] = prefix[i - 1][num];
            prefix[i][num ^ 1] = prefix[i - 1][num] + i;
        }
        for(int i = n; i >= 1; i--){
            num = s[i - 1] - '0';
            suffix[i][num] = suffix[i + 1][num];
            suffix[i][num ^ 1] = suffix[i + 1][num] + n - i + 1;
        }
        long long ans = LLONG_MAX;
        for(int i = 0; i <= n; i++){
            ans = min({ans, prefix[i][0] + suffix[i + 1][0], prefix[i][1] + suffix[i + 1][1]});
        }
        return ans;
    }
};