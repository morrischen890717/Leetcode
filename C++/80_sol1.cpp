class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num = INT_MIN;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > num){
                num = nums[i];
                cnt = 1;
            }
            else{
                cnt++;
                if(cnt > 2){
                    nums.erase(nums.begin() + i);
                    i--;
                }
            }
        }
        return nums.size();    
    }
};