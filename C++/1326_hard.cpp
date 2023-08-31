class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        // using Greedy
        // time complexity: O(N), space complexity: O(N)
        // reference: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/solutions/506853/java-a-general-greedy-solution-to-process-similar-problems/
        // this problem is similar to Problem 45: Jump Game II(https://leetcode.com/problems/jump-game-ii/description/)
        int ans = 0;
        int size = ranges.size();
        vector<int> jump(n + 1);
        for(int i = 0; i < size; i++){
            jump[max(0, i - ranges[i])] = max(jump[max(0, i - ranges[i])], i + ranges[i]);
        }
        int end = 0, canReach = 0;
        for(int i = 0; end < n; end = canReach){
            ans++;
            while(i <= end){
                canReach = max(canReach, jump[i]);
                i++;
            }
            if(end == canReach)
                return -1;
        }
        return ans;
    }
};