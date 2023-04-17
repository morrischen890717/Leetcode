class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        for(int i = 0; i < n; i++){
            if(i < 2 || nums[i] > nums[cur - 2]){
                nums[cur] = nums[i];
                cur++;
            }
        }
        return cur;    
    }
};