class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_num = INT_MIN, max_len = 0, len = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == max_num)
                len++;
            else if(nums[i] > max_num){
                max_num = nums[i];
                max_len = len = 1;
            }
            else
                len = 0;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};