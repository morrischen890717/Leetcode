class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double sum = 0.0;
        priority_queue<pair<double, pair<int, int>>> pq;
        for(vector<int>& c: classes){
            if(c[0] == c[1])
                sum += 1.0;
            else
                pq.push({(double)(c[0] + 1) / (c[1] + 1) - (double)c[0] / c[1], {c[0], c[1]}});
        }
        for(int i = 0; i < extraStudents && !pq.empty(); i++){
            pair<double, pair<int, int>> p = pq.top();
            pq.pop();
            p.second.first++;
            p.second.second++;
            p.first = (double)(p.second.first + 1) / (p.second.second + 1) - (double)p.second.first / p.second.second;
            pq.push(p);
        }
        while(!pq.empty()){
            sum += (double)pq.top().second.first / pq.top().second.second;
            pq.pop();
        }
        return sum / classes.size();
    }
};