class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        using namespace std;
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int num_size = nums.size();
        vector<int> ans;
        for(int i = 0; i < num_size; i++){
            for(int j = i + 1; j < num_size; j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};