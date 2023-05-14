class Solution {
public:
    int diff_cnt(string a, string b){
        int len = a.length();
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(a[i] != b[i])
                cnt++;
        }
        return cnt;
    }
    int solve(unordered_map<string, int>& dp, unordered_map<string, bool>& visited, string curGene, string endGene, vector<string>& bank){
        if(curGene == endGene)
            return 0;
        if(visited[curGene])
            return 10000;
        if(dp.count(curGene) > 0 && dp[curGene] != 10000)
            return dp[curGene];
        dp[curGene] = 10000;
        visited[curGene] = true;
        for(int i = 0; i < bank.size(); i++){
            if(diff_cnt(curGene, bank[i]) == 1){
                dp[curGene] = min(dp[curGene], 1 + solve(dp, visited, bank[i], endGene, bank));
            }
        }
        visited[curGene] = false;
        return dp[curGene];
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        unordered_map<string, int> dp;
        unordered_map<string, bool> visited;
        int ans = solve(dp, visited, startGene, endGene, bank);
        return (ans == 10000 ? -1 : ans);
    }
};