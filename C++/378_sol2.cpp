class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // using min-heap, time complexity: O(klogk), space complexity: O(k)
        int n = matrix.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ptr(n, 0);  // ptr[i] records the current pointer in sorted matrix[i]
        for(int i = 0; i < n; i++){
            pq.push({matrix[i][0], i});
        }
        pair<int, int> p;
        for(int i = 0; i < k; i++){
            p = pq.top();
            pq.pop();
            ptr[p.second]++;
            if(ptr[p.second] < n)
                pq.push({matrix[p.second][ptr[p.second]], p.second});    
        }
        return p.first;
    }
};