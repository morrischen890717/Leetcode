class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // using unordered_map and Greedy
        int n = arr.size();
        unordered_map<int, int> cnt;
        vector<int> bucket(n + 1, 0);
        for(int num: arr){
            cnt[num]++;
        }
        int ans = 0;
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            bucket[it->second]++;
            ans++;
        }
        for(int i = 1; i <= n && k > 0; i++){
            ans -= min(bucket[i], k / i);
            k -= i * bucket[i];
        }
        return ans;
    }
};