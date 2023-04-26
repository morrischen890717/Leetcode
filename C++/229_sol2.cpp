class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;
        unordered_map<int, int> m;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            m[nums[i]]++;
            if(m[nums[i]] == k + 1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};