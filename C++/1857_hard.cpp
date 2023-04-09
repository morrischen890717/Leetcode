class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int l = colors.length();
        int n = edges.size();
        int k = 26; // 'a' to 'z' every color
        vector<vector<int>> e(l, vector<int> ());
        vector<int> indegree(l, 0);
        for(int i = 0; i < n; i++){
            int from = edges[i][0];
            int to = edges[i][1];
            e[from].push_back(to);
            indegree[to]++;
        }
        vector<vector<int>> count(l, vector<int> (k, 0)); // DP vector
        queue<int> q;
        for(int i = 0; i < l; i++){
            count[i][colors[i] - 'a']++;
            if(indegree[i] == 0)
                q.push(i);
        }
        int visited = 0;
        int ans = 0;
        while(!q.empty()){
            int id = q.front();
            q.pop();
            visited++;
            for(int i = 0; i < e[id].size(); i++){
                int next = e[id][i];
                for(int j = 0; j < k; j++){
                    count[next][j] = max(count[next][j], count[id][j] + (j == colors[next] - 'a' ? 1 : 0));
                }
                indegree[next]--;
                if(indegree[next] == 0) // Topological Sort (the nodes which before node {next} have all been traversed)
                    q.push(next);
            }
            ans = max(ans, *max_element(count[id].begin(), count[id].end()));
        }
        return visited == l ? ans : -1;
    }
};