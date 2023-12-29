class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // using bottom-up DP
        // time complexity: O(N * d), space complexity: O(N), , where N == jobDifficulty.size()
        // reference: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/solutions/490316/java-c-python3-dp-o-nd-solution/?envType=daily-question&envId=2023-12-29
        int n = jobDifficulty.size();
        if(n < d)
            return -1;
        vector<int> dp(n, 1000); // dp[i] stands for the optimal solution for d days with i jobs.
        for(int i = 0; i < d; i++){
            vector<int> dp2(n), stack;
            for(int j = i; j < n; j++){
                dp2[j] = j > 0 ? dp[j - 1] + jobDifficulty[j] : jobDifficulty[j];
                while(!stack.empty() && jobDifficulty[j] >= jobDifficulty[stack.back()]){
                    dp2[j] = min(dp2[j], dp2[stack.back()] - jobDifficulty[stack.back()] + jobDifficulty[j]);
                    stack.pop_back();
                }
                if(!stack.empty())
                    dp2[j] = min(dp2[j], dp2[stack.back()]);
                stack.push_back(j);
            }
            dp = dp2;
        }
        return dp[n - 1];
    }
}; 