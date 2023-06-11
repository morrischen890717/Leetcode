class Solution {
public:
    int trap(vector<int>& height) {
        /*
        using two pointers
        time complexity: O(N), space complexity: O(1)
        reference: https://leetcode.com/problems/trapping-rain-water/solutions/17357/sharing-my-simple-c-code-o-n-time-o-1-space/
        */
        int n = height.size();
        int l = 0, r = n - 1;
        int max_left = -1, max_right = -1;
        int ans = 0;
        while(l <= r){
            if(height[l] <= height[r]){
                if(max_left <= height[l])
                    max_left = height[l];
                else
                    ans += max_left - height[l];
                l++;
            }
            else{
                if(max_right <= height[r])
                    max_right = height[r];
                else
                    ans += max_right - height[r];
                r--;
            }
        }
        return ans;
    }
};