class Solution {
public:
    void dfs(unordered_map<string, vector<string>>& graph, unordered_map<string, vector<double>>& edges, unordered_map<string, bool>& visited, string& end, string cur, double& val, bool& found){
        if(cur == end){
            found = true;
            return;
        }
        for(int i = 0; i < graph[cur].size(); i++){
            if(visited[graph[cur][i]])
                continue;
            visited[graph[cur][i]] = true;
            val *= edges[cur][i];
            dfs(graph, edges, visited, end, graph[cur][i], val, found);
            if(found)
                return;
            else{
                visited[graph[cur][i]] = false;
                val /= edges[cur][i];
            }
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, vector<double>> edges;
        vector<double> ans;
        for(int i = 0; i < equations.size(); i++){
            graph[equations[i][0]].push_back(equations[i][1]);
            edges[equations[i][0]].push_back(values[i]);
            graph[equations[i][1]].push_back(equations[i][0]);
            edges[equations[i][1]].push_back(1 / values[i]);
        }
        for(auto& q: queries){
            if(graph.count(q[0]) == 0 || graph.count(q[1]) == 0)
                ans.push_back(-1.0);
            else{
                unordered_map<string, bool> visited;
                visited[q[0]] = true;
                double val = 1.0;
                bool found = false;
                dfs(graph, edges, visited, q[1], q[0], val, found);
                if(found)
                    ans.push_back(val);
                else
                    ans.push_back(-1.0);
            }
        }
        return ans;
    }
};