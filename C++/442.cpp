class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*
        time complexity: O(N), space complexity: O(1)
        The concept of this algorithm: If two num in vector nums have same value,
        then they will map to the same position(target - 1), so if nums[target - 1] < 0, we know that it appears twice.
        e.g. nums[3] = 5, nums[4] = 2, nums[7] = 5,
        when i == 3, we check the value of nums[4] (4 = 5 - 1) and change its value from 2 to -2, 
        and when i == 7, we check the value of nums[4] again and get the negative value, so we know that 5 appears twice.
        */
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            int target = abs(nums[i]);
            if(nums[target - 1] < 0)
                ans.push_back(target);
            else
                nums[target - 1] *= -1;
        }
        return ans;
    }
};