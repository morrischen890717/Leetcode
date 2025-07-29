class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> last(32, -1);
        for(int i = n - 1; i >= 0; i--){
            int farest = i;
            for(int j = 0; j < 32; j++){
                if(nums[i] & (1 << j))
                    last[j] = i;
                farest = max(farest, last[j]);
            }
            nums[i] = farest - i + 1;
        }
        return nums;
    }
};