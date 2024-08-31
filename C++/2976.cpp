class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // using Floyd-Warshall Algorithm
        vector<vector<int>> dist(26, vector<int> (26, 1e7));
        for(int i = 0; i < original.size(); i++){
            dist[original[i] - 'a'][changed[i] - 'a'] = min(dist[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for(int i = 0; i < 26; i++){
            dist[i][i] = 0;
        }
        for(int k = 0; k < 26; k++){
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < 26; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.length(); i++){
            if(dist[source[i] - 'a'][target[i] - 'a'] == 1e7)
                return -1;
            ans += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};