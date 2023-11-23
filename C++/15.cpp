class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // using sort and two-pointers
        // time complexity: O(N^2)
        // reference: https://leetcode.com/problems/3sum/solutions/7402/share-my-ac-c-solution-around-50ms-o-n-n-with-explanation-and-comments/?envType=featured-list&envId=top-interview-questions%3FenvType%3Dfeatured-list&envId=top-interview-questions
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum < -nums[i])
                    l++;
                else if(sum > -nums[i])
                    r--;
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l < r && nums[l + 1] == nums[l]){
                        l++;
                    }
                    while(l < r && nums[r - 1] == nums[r]){
                        r--;
                    }
                    l++;
                    r--;
                }
            }
            while(i + 1 < n && nums[i + 1] == nums[i]){
                i++;
            }
        }
        return ans;
    }
};