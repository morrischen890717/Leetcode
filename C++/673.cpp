class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        /*
        using bottom-up DP
        time complexity: O(N^2)
        */
        int n = nums.size();
        vector<pair<int, int>> maxIncrease(n, {1, 1}); // {maximum increasing len which ends with nums[i], number of maximum increasing len}
        int max_len = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    if(maxIncrease[i].first < maxIncrease[j].first + 1)
                        maxIncrease[i] = {maxIncrease[j].first + 1, maxIncrease[j].second};
                    else if(maxIncrease[i].first == maxIncrease[j].first + 1)
                        maxIncrease[i].second += maxIncrease[j].second;
                }
            }

            if(max_len < maxIncrease[i].first){
                max_len = maxIncrease[i].first;
                cnt = maxIncrease[i].second;
            }
            else if(max_len == maxIncrease[i].first)
                cnt += maxIncrease[i].second;
        }
        return cnt;
    }
};