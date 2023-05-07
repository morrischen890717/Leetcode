class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> m;
        vector<int> prefix(n);
        vector<int> suffix(n);
        int cnt = 0;
        prefix[0] = 1;
        m[nums[0]] = true;
        for(int i = 1; i < n; i++){
            if(m.count(nums[i]) == 0){
                m[nums[i]] = true;
                prefix[i] = prefix[i - 1] + 1;
            }
            else{
                prefix[i] = prefix[i - 1];
            } 
        }
        m.clear();
        suffix[n - 1] = 0;
        for(int i = n - 1; i >= 1; i--){
            if(m.count(nums[i]) == 0){
                m[nums[i]] = true;
                suffix[i - 1] = suffix[i] + 1;
            }
            else{
                suffix[i - 1] = suffix[i];
            }
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(prefix[i] - suffix[i]);
        }
        return ans;
    }
};