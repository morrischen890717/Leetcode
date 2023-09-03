class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(int num: nums){
            sum += num % 2 ? 0 : num;
        }
        for(vector<int>& q: queries){
            if(nums[q[1]] % 2 == 0)
                sum -= nums[q[1]];
            nums[q[1]] += q[0];
            if(nums[q[1]] % 2 == 0)
                sum += nums[q[1]];
            ans.push_back(sum);
        }
        return ans;
    }
};