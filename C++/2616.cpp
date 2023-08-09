class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        /*
        using binary search
        time complexity: O(NlogN + Nlog(max(nums))), space complexity: O(logN) (because of sort())
        reference: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/solutions/3395750/java-c-python-binary-search/
        */
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n - 1] - nums[0];
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int i = 1; i < n && cnt < p; i++){
                if(nums[i] - nums[i - 1] <= mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt >= p)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};