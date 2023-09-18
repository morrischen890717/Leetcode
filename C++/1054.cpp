class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        // using priority_queue, bucket, and Greedy
        int n = barcodes.size();
        vector<int> ans(n, 0);
        vector<int> cnt(10001, 0);
        for(int i = 0; i < n; i++){
            cnt[barcodes[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i])
                pq.push({cnt[i], i});
        }
        pair<int, int> cur, pre = {-1, -1};
        for(int i = 0; i < n; i++){
            cur = pq.top();
            pq.pop();
            ans[i] = cur.second;
            cur.first--;
            pq.push(pre);
            pre = cur;
        }
        return ans;
    }
};