class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // using unordered_set and bottom-up DP
        // reference: https://leetcode.com/problems/minimum-cost-for-tickets/solutions/226659/two-dp-solutions-with-pictures/
        unordered_set<int> s(days.begin(), days.end());
        vector<int> dp(30, 0);
        for(int i = days[0]; i <= days.back(); i++){
            if(s.find(i) == s.end())
                dp[i % 30] = dp[(i - 1) % 30];
            else
                dp[i % 30] = min({dp[(i - 1 + 30) % 30] + costs[0], dp[(i - 7 + 30) % 30] + costs[1], dp[(i - 30 + 30) % 30] + costs[2]}); // +30 to make the value always be positive
        }
        return dp[days.back() % 30];
    }
};