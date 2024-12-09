class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<int> cnt(n, 0);
        for(int i = 1; i < n; i++){
            cnt[i] = (nums[i] & 1) ^ (nums[i - 1] & 1) ? cnt[i - 1] : cnt[i - 1] + 1;
        }
        for(vector<int>& q: queries){
            if(cnt[q[1]] == cnt[q[0]])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};