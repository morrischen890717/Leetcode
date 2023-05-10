class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        vector<int> dp(n, 1); // dp[i] represents the max length of divisible subset which nums[i] is the smallest element in the subset
        vector<int> backtrack(n, -1);
        for(int i = n - 1; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(nums[j] % nums[i] == 0){ // if true, then all the elements in dp[j] can also be divisible by nums[i]
                    if(dp[j] + 1 > dp[i]){ // +1 represents nums[i]
                        dp[i] = dp[j] + 1;
                        backtrack[i] = j;
                    }
                }
            }
        }
        int start = -1;
        int num = INT_MIN;
        for(int i = 0; i < n; i++){
            if(dp[i] > num){
                num = dp[i];
                start = i;
            }
        }
        for(int i = 0; i < num; i++){
            ans.push_back(nums[start]);
            start = backtrack[start]; // backtracking
        }
        return ans;
    }
};