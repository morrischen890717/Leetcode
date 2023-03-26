class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]){
                index = i;
                break;
            }
        }
        for(int i = n - 1; i > index && index != -1; i--){
            if(nums[index] < nums[i]){
                swap(nums[index], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
        return;
    }
};