class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
        using bottom-up DP
        reference:
        https://leetcode.com/problems/last-stone-weight-ii/solutions/294888/java-c-python-easy-knapsacks-dp/
        https://leetcode.com/problems/last-stone-weight-ii/solutions/295167/java-beat-100-with-nice-explanation/
        main idea:
        This problem is a knapsack problem.
        This question eaquals to partition an array into 2 subsets whose difference is minimal
            (1) S1 + S2  = S
            (2) S1 - S2 = diff  
        => diff = S - 2 * S2, where S2 is the subset with smaller sum
        So, we need to record the subset sum values which might appear in S2, and we will record it by vector dp
        */
        int n = stones.size();
        vector<bool> dp(1501, false); // record if the sum that S2 may possible is or not, note that we just need to record the subset which has the smaller subset sum
        dp[0] = true;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += stones[i];
            for(int j = min(1500, sum); j >= stones[i]; j--){ // if j > 1500, it will be S1, which is the bigger subset
                if(!dp[j]) // if S2 has already possible to have subset sum j, then we do not need to update it
                    dp[j] = dp[j - stones[i]];
            }
        }
        for(int j = sum / 2; j >= 0; j--){ // sum / 2 is because S2 will has at most sum/2 with its subset sum (S2 is the smaller subset)
            if(dp[j])
                return sum - 2 * j;
        }
        return 0;
    }
};