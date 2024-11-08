class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> ans;
        int n = nums.size();
        int cur_xor = 0;
        for(int num: nums){
            cur_xor ^= num;
        }
        for(int i = n - 1; i >= 0; i--){
            ans.push_back(((1 << maximumBit) - 1) ^ cur_xor);
            cur_xor ^= nums[i];
        }
        return ans;
    }
};