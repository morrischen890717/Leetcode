class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // using sort and binary search
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.back() - nums[0];
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int i = 0; i < nums.size(); i++){
                int j = i + 1;
                while(j < nums.size() && nums[j] - nums[i] <= mid){
                    j++;
                }
                cnt += j - i - 1;
            }
            if(cnt >= k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};