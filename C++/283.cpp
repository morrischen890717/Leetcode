class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        int n = nums.size();
        int ptr = 0;
        for(int i = 0; i < n; i++){
            if(nums[i])
                nums[ptr++] = nums[i];
        }
        for(; ptr < n; ptr++){
            nums[ptr] = 0;
        }
        return;
    }
};