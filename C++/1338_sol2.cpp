class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // using unordered_map and priority_queue
        // time complexity: O(NlogN)
        int remove = arr.size() / 2;
        unordered_map<int, int> cnt;
        for(int num: arr){
            cnt[num]++;
        }
        priority_queue<int> pq;
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            pq.push(it->second);
        }
        int ans = 0;
        while(remove > 0){
            remove -= pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};