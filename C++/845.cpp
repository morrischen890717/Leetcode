class Solution {
public:
    int longestMountain(vector<int>& arr) {
        // time complexity: O(N), space complexity: O(1)
        // reference: https://leetcode.com/problems/longest-mountain-in-array/solutions/937652/python-one-pass-o-1-space-explained/
        int n = arr.size();
        int ans = 0, cnt = 0;
        int state = 0; // 0: pending, 1: increasing, 2: decreasing
        for(int i = 1; i < n; i++){
            if(state == 0 && arr[i] > arr[i - 1]){
                state = 1;
                cnt = 2;
            }
            else if(state == 1){
                if(arr[i] > arr[i - 1])
                    cnt++;
                else if(arr[i] < arr[i - 1]){
                    state = 2;
                    cnt++;
                }
                else{
                    state = 0;
                    cnt = 0;
                }
            }
            else if(state == 2){
                ans = max(ans, cnt);
                if(arr[i] < arr[i - 1])
                    cnt++;
                else if(arr[i] > arr[i - 1]){
                    state = 1;
                    cnt = 2;
                }
                else{
                    state = 0;
                    cnt = 0;
                }
            }
        }
        if(state == 2)
            ans = max(ans, cnt);
        return ans;
    }
};