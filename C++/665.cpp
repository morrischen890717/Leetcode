class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i < n - 1; i++){
            if(nums[i] < nums[i - 1] && nums[i + 1] < nums[i])
                return false;
            else if(nums[i] < nums[i - 1]){
                if(cnt >= 1)
                    return false;
                cnt++; // modify nums[i - 1]
            }
            else if(nums[i + 1] < nums[i]){
                if(cnt >= 1)
                    return false;
                if(nums[i + 1] < nums[i - 1])
                    nums[i + 1] = nums[i]; // modify nums[i + 1]
                else
                    nums[i] = nums[i - 1]; // modify nums[i]
                cnt++;
            }
        }
        return true;
    }
};