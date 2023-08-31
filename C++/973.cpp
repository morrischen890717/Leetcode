class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // using priority queue
        // time complexity: O(N), space complexity: O(K)
        vector<vector<int>> ans(k);
        int n = points.size();
        priority_queue<pair<int, int>> pq; // {distance, id}
        for(int i = 0; i < n; i++){
            int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({d, i});
            if(pq.size() > k)
                pq.pop();
        }
        for(int i = 0; i < k; i++){
            ans[i] = points[pq.top().second];
            pq.pop();
        }
        return ans;
    }
};