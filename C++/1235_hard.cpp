class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // using DP and sort
        // reference: https://leetcode.com/problems/maximum-profit-in-job-scheduling/solutions/409009/java-c-python-dp-solution/?envType=daily-question&envId=2024-01-06
        int n = endTime.size();
        vector<vector<int>> jobs(n);
        for(int i = 0; i < n; i++){
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp; // {endTime, maxTotalProfit}
        dp[0] = 0;
        for(vector<int>& job: jobs){
            int cur_profit = prev(dp.upper_bound(job[1]))->second + job[2];
            if(cur_profit > dp.rbegin()->second)
                dp[job[0]] = cur_profit;
        }
        return dp.rbegin()->second;
    }
};