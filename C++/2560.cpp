class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        // using binary search
        // reference: https://leetcode.com/problems/house-robber-iv/solutions/3143697/java-c-python-binary-search-o-1-space/?envType=daily-question&envId=2025-03-15
        int n = nums.size();
        int l = 1, r = 1e9;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};