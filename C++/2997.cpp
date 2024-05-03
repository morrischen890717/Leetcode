class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int res = 0;
        for(int num: nums){
            res ^= num;
        }
        res ^= k;
        while(res){
            if(res & 1)
                ans++;
            res >>= 1;
        }
        return ans;
    }
};