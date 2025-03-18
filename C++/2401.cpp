class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int l = 0, bits = 0;
        for(int r = 0; r < n; r++){
            while(bits & nums[r]){
                bits ^= nums[l++];
            }
            ans = max(ans, r - l + 1);
            bits |= nums[r];
        }
        return ans;
    }
};