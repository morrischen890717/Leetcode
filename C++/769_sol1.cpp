class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int cnt = 0;
        vector<bool> appeared(n);
        for(int i = 0; i < n; i++){
            if(arr[i] <= i)
                cnt++;
            if(appeared[i]) 
                cnt++;
            appeared[arr[i]] = true;
            if(cnt == i + 1)
                ans++;
        }
        return ans;
    }
};