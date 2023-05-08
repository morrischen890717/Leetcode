class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int pre_diff = INT_MAX;
        int max_len = 1;
        for(int i = 1; i < n; i++){
            int diff = nums[i] - nums[i - 1];
            if((pre_diff == INT_MAX && diff != 0) || pre_diff * diff < 0)
                max_len += 1;
            pre_diff = (diff == 0 ? pre_diff : diff);
        }
        return max_len;
    }
};