class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // using sliding window
        // reference: https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/solutions/6357735/merge-k-1-gaps/?envType=daily-question&envId=2025-07-09
        int n = startTime.size(), ans = 0;
        vector<int> gaps(n + 1);
        gaps[0] = startTime[0], gaps[n] = eventTime - endTime[n - 1];
        for(int i = 1; i < n; i++){
            gaps[i] = startTime[i] - endTime[i - 1];
        }
        int sum = 0;
        for(int i = 0; i <= k; i++){
            sum += gaps[i];
        }
        ans = sum;
        for(int i = k + 1; i <= n; i++){
            sum += gaps[i] - gaps[i - k - 1];
            ans = max(ans, sum);
        }
        return ans;
    }
};