class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, nums[0]);
        vector<int> suffix(n, nums[n - 1]);
        vector<int> ans;
        int product;
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i];
            suffix[n - 1 - i] = suffix[n - i] * nums[n - 1 - i];
        }
        for(int i = 0; i < n; i++){
            if(i == 0)
                product = suffix[1];
            else if(i == n - 1)
                product = prefix[n - 2];
            else
                product = prefix[i - 1] * suffix[i + 1];
            ans.push_back(product);
        }
        return ans;
    }
};