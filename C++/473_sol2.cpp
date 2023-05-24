class Solution {
public:
    bool backtrack(vector<int>& matchsticks, int n, vector<bool>& visited, int curId, int curSum, int target, int sideNum){
        if(sideNum == 3)
            return true;
        if(curSum == target)
            return backtrack(matchsticks, n, visited, 0, 0, target, sideNum + 1);
        for(int i = curId; i < n; i++){
            if(visited[i] || curSum + matchsticks[i] > target)
                continue;
            visited[i] = true;
            if(backtrack(matchsticks, n, visited, i + 1, curSum + matchsticks[i], target, sideNum))
                return true;
            visited[i] = false;
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        // reference: https://leetcode.com/problems/matchsticks-to-square/solutions/1273756/c-simple-and-clean-backtracking-commented-solution/
        int n = matchsticks.size();
        vector<bool> visited(n, false);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += matchsticks[i];
        }
        if(sum % 4 != 0)
            return false;
        return backtrack(matchsticks, n, visited, 0, 0, sum / 4, 0);
    }
};