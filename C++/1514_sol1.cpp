class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        /*
        using Dijkstra Algorithm
        reference: https://leetcode.com/problems/path-with-maximum-probability/solutions/731767/java-python-3-2-codes-bellman-ford-and-dijkstra-s-algorithm-w-brief-explanation-and-analysis/
        */
        vector<vector<pair<int, int>>> neighbor(n); // {node index, index in edges}
        vector<double> prob(n, 0.0); // prob[i] stores the maximum probability of the path from start to i
        priority_queue<pair<double, int>> pq;
        for(int i = 0; i < edges.size(); i++){
            neighbor[edges[i][0]].push_back({edges[i][1], i});
            neighbor[edges[i][1]].push_back({edges[i][0], i});
        }
        prob[start] = 1.0;
        pq.push({prob[start], start});
        while(!pq.empty()){
            pair<double, int> top = pq.top();
            double p = top.first;
            int id = top.second;
            pq.pop();
            if(id == end)
                return p;
            for(int i = 0; i < neighbor[id].size(); i++){
                if(p * succProb[neighbor[id][i].second] > prob[neighbor[id][i].first]){
                    prob[neighbor[id][i].first] = p * succProb[neighbor[id][i].second];
                    pq.push({prob[neighbor[id][i].first], neighbor[id][i].first});
                }
            }
        }
        return 0.0;
    }
};