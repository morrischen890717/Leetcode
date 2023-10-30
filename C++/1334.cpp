class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // using Floyd–Warshall algorithm
        // time complexity: O(N^3), space complexity: O(N^2)
        // reference: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/solutions/490312/java-c-python-easy-floyd-algorithm/
        vector<vector<int>> graph(n, vector<int> (n, 1e6));
        for(vector<int>& edge: edges){
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i < n; i++){
            graph[i][i] = 0;
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
        int min_cnt = INT_MAX;
        int ans = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(graph[i][j] <= distanceThreshold)
                    cnt++;
            }
            if(cnt <= min_cnt){
                min_cnt = cnt;
                ans = i;
            }
        }
        return ans;
    }
};