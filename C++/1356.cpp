class Solution {
public:
    int cnt_1(int num){
        int cnt = 0;
        while(num){
            cnt += (num & 1);
            num >>= 1;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        // using priority_queue
        priority_queue<pair<int, int>> pq;
        for(int num: arr){
            int num_1 = cnt_1(num);
            pq.push({-num_1, -num});
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(-pq.top().second);
            pq.pop();
        }
        return ans;
    }
};