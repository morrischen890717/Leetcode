class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<int> pq;
        for(int gift: gifts){
            pq.push(gift);
        }
        for(int i = 0; i < k; i++){
            int cur = pq.top();
            pq.pop();
            pq.push(sqrt(cur));
        }
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};