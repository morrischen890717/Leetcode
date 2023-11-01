class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        // using sliding window
        // time complexity: O(N)
        int n = arr.size();
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(i >= k)
                sum -= arr[i - k];
            if(i >= k - 1 && sum >= k * threshold)
                ans++;
        }
        return ans;
    }
};