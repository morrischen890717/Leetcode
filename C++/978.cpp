class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        if(arr.size() < 2)
            return arr.size();
        int ans = 0;
        int n = arr.size();
        int len = arr[0] == arr[1] ? 1 : 2;
        for(int i = 1; i < n - 1; i++){
            if((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i - 1] > arr[i] && arr[i] < arr[i + 1]))
                len++;
            else{
                ans = max(ans, len);
                len = arr[i] == arr[i + 1] ? 1 : 2;
            }
        }
        ans = max(ans, len);
        return ans;
    }
};