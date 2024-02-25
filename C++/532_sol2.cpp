class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // using sort and binary search
        // time complexity: O(NlogN), space complexity: O(1)
        int ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = n - 1, target = nums[i] + k;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(nums[mid] == target){
                    ans++;
                    break;
                }
                else if(nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return ans;
    }
};