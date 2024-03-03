class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // using two-pointers
        // time complexity: O(N)
        int n = nums.size();
        vector<int> ans;
        int pos = -1;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] * nums[i] <= 0){
                pos = i;
                break;
            }
        }
        int l, r;
        if(pos == -1){
            l = nums[0] >= 0 ? -1 : n - 1;
            r = nums[0] >= 0 ? 0 : n;
        }
        else{
            l = pos - 1;
            r = pos;
        }
        while(l >= 0 && r < n){
            if(abs(nums[l]) < nums[r]){
                ans.push_back(nums[l] * nums[l]);
                l--;
            }
            else{
                ans.push_back(nums[r] * nums[r]);
                r++;
            }
        }
        while(l >= 0){
            ans.push_back(nums[l] * nums[l]);
            l--;
        }
        while(r < n){
            ans.push_back(nums[r] * nums[r]);
            r++;
        }
        return ans;
    }
};