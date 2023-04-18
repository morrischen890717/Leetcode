class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = max_element(nums.begin(), nums.end()) - nums.begin();
        for(int i = pivot; i < pivot + n; i++){
            if(nums[i % n] != nums[pivot]){
                pivot = i % n;
                break;
            }
        }
        int l = pivot, r = pivot + n;
        int mid;
        while(l <= r){
            mid = (l + r) / 2;
            if(nums[mid % n] == target)
                return true;
            else if(nums[mid % n] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false; 
    }
};