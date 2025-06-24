class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        int end = -1;
        for(int i = 0; i < n; i++){
            if(nums[i] == key){
                for(int j = max({0, i - k, end + 1}); j <= min(n - 1, i + k); j++){
                    ans.push_back(j);
                    end = j;
                }
            }
        }
        return ans;
    }
};