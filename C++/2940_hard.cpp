class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        // using priority_queue
        // reference: https://leetcode.com/problems/find-building-where-alice-and-bob-can-meet/solutions/4304269/java-c-python-priority-queue/?envType=daily-question&envId=2024-12-22
        int n = heights.size();
        vector<int> ans(queries.size(), -1);
        vector<vector<vector<int>>> v(n);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int k = 0; k < queries.size(); k++){
            int i = queries[k][0], j = queries[k][1];
            if(i < j && heights[i] < heights[j])
                ans[k] = j;
            else if(i > j && heights[i] > heights[j])
                ans[k] = i;
            else if(i == j)
                ans[k] = i;
            else
                v[max(i, j)].push_back({max(heights[i], heights[j]), k});
        }
        for(int k = 0; k < n; k++){
            while(!pq.empty() && pq.top()[0] < heights[k]){
                ans[pq.top()[1]] = k;
                pq.pop();
            }
            for(vector<int>& tmp: v[k]){
                pq.push(tmp);
            }
        }
        return ans;
    }
};