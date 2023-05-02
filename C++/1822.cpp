class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int x = 1;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                x = 0;
                break;
            }
            else if(nums[i] < 0){
                x = -x;
            }
        }
        return (x > 0 ? 1 : (x < 0 ? -1 : 0));
    }
};