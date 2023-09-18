class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        // using priority_queue and binary search
        int m = mat.size(), n = mat[0].size();
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < m; i++){
            int l = 0, r = n - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(mat[i][mid] == 1)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            pq.push({l, i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans(k);
        for(int i = k - 1; i >= 0; i--){
            ans[i] = pq.top().second;
            pq.pop();
        }
        return ans;
    }
};