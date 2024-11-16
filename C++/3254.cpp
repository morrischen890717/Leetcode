class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int start = 0;
        for(int i = 0; i < n; i++){
            if(i - 1 >= 0 && nums[i] != nums[i - 1] + 1)
                start = i;
            if(i >= k - 1){
                if(i - start + 1 >= k)
                    ans.push_back(nums[i]);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};