class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // time complexity: O(N), space complexity: O(1)
        int n = nums.size();
        // assume the triplet subsequence to be (small, medium, big)
        int small = INT_MAX, medium = INT_MAX;
        for(int i = 0; i < n; i++){
            if(nums[i] > medium) // nums[i] is big
                return true;
            else if(nums[i] > small) // try to make medium smaller
                medium = min(medium, nums[i]);
            else // try to make small smaller
                small = nums[i];
        }
        return false;
    }
};