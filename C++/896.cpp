class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int slope = 0;
        for(int i = 1; i < nums.size(); i++){
            int diff = nums[i] - nums[i - 1];
            if(slope == 0 && diff != 0)
                slope = diff > 0 ? 1 : -1;
            if(diff * slope < 0)
                return false;
        }
        return true;
    }
};