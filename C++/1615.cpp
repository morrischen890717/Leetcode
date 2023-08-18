class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // time complexity: O(N^2), space complexity: O(N^2)
        int ans = 0;
        vector<int> cnt(n, 0);
        vector<vector<bool>> connected(n, vector<bool> (n, false));
        for(vector<int>& road: roads){
            cnt[road[0]]++;
            cnt[road[1]]++;
            connected[road[0]][road[1]] = true;
            connected[road[1]][road[0]] = true;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int rank = connected[i][j] ? cnt[i] + cnt[j] - 1 : cnt[i] + cnt[j];
                ans = max(ans, rank);
            }
        }
        return ans;
    }
};