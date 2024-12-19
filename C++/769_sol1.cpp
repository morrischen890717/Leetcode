class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        int max_val = INT_MIN;
        for(int i = 0; i < n; i++){
            max_val = max(max_val, arr[i]);
            if(i == max_val)
                ans++;
        }
        return ans;
    }
};