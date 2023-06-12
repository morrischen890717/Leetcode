class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n == 0)
            return ans;
        string s = to_string(nums[0]);
        int prev = nums[0], start = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] != prev + 1){
                if(prev == start)
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(prev));
                start = nums[i];
            }
            prev = nums[i];
        }
        if(prev == start)
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start) + "->" + to_string(prev));
        return ans;
    }
};