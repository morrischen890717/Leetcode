class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // using sliding window
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solutions/830480/c-o-n-sliding-window-explanation-with-illustrations/?envType=daily-question&envId=2024-11-15
        int n = arr.size();
        int left = -1, right = -1;
        for(int i = 0; i < n; i++){
            if(i + 1 < n && arr[i] > arr[i + 1] && left == -1)
                left = i;
            if(i - 1 >= 0 && arr[i - 1] > arr[i])
                right = i;
        }
        if(left == -1)
            return 0;
        int ans = min(right, n - left - 1);
        int l = 0, r = right;
        while(l <= left && r < n){
            if(arr[l] <= arr[r]){
                ans = min(ans, r - l - 1);
                l++;
            }
            else
                r++;
        }
        return ans;
    }
};