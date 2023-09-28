class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        int n = nums.size();
        int even_ptr = 0, odd_ptr = n - 1;
        while(even_ptr < odd_ptr){
            while(even_ptr < odd_ptr && (nums[even_ptr] & 1) == 0){
                even_ptr++;
            }
            while(even_ptr < odd_ptr && (nums[odd_ptr] & 1)){
                odd_ptr--;
            }
            if(even_ptr < odd_ptr)
                swap(nums[even_ptr], nums[odd_ptr]);
            even_ptr++;
            odd_ptr--;
        }
        return nums;
    }
};