class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        /*
        using Bellman-Ford Algorithm
        reference: https://leetcode.com/problems/path-with-maximum-probability/solutions/731767/java-python-3-2-codes-bellman-ford-and-dijkstra-s-algorithm-w-brief-explanation-and-analysis/
        */
        vector<vector<pair<int, int>>> neighbor(n); // {node index, index in edges}
        vector<double> prob(n, 0.0); // prob[i] stores the maximum probability of the path from start to i
        queue<int> q;
        for(int i = 0; i < edges.size(); i++){
            neighbor[edges[i][0]].push_back({edges[i][1], i});
            neighbor[edges[i][1]].push_back({edges[i][0], i});
        }
        prob[start] = 1.0;
        q.push(start);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int i = 0; i < neighbor[cur].size(); i++){
                if(prob[cur] * succProb[neighbor[cur][i].second] > prob[neighbor[cur][i].first]){
                    prob[neighbor[cur][i].first] = prob[cur] * succProb[neighbor[cur][i].second];
                    q.push(neighbor[cur][i].first);
                }
            }
        }
        return prob[end];
    }
};