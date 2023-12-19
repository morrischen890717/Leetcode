class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0, ptr_0 = 0, ptr_2 = n - 1;
        while(i <= ptr_2){
            if(nums[i] == 0){
                swap(nums[i], nums[ptr_0++]);
                i++;
            }
            else if(nums[i] == 2)
                swap(nums[i], nums[ptr_2--]);
            else
                i++;
        }
        return;
    }
};