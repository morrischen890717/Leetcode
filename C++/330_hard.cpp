class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int ans = 0;
        long long reach = 0;
        int i = 0;
        while(reach < n){
            if(i < nums.size() && reach >= nums[i] - 1){
                reach += nums[i];
                i++;
            }
            else{
                ans++;
                reach += reach + 1;
            }
        }
        return ans;
    }
};