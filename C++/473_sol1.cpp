class Solution {
public:
    bool dfs(vector<int>& matchsticks, int n, vector<int>& sideLength, int cur, int target){
        if(sideLength[0] == target && sideLength[1] == target && sideLength[2] == target && sideLength[3] == target)
            return true;
        if(cur == n)
            return false;
        for(int i = 0; i < sideLength.size(); i++){
            if(sideLength[i] + matchsticks[cur] > target)
                continue;
            if(find(sideLength.begin(), sideLength.begin() + i, sideLength[i]) != sideLength.begin() + i) // has same length with another side that has been tackled
                continue;
            sideLength[i] += matchsticks[cur];
            if(dfs(matchsticks, n, sideLength, cur + 1, target))
                return true;
            sideLength[i] -= matchsticks[cur];
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        // reference: https://leetcode.com/problems/matchsticks-to-square/solutions/95744/cpp-6ms-solution-with-dfs/
        int n = matchsticks.size();
        vector<int> sideLength(4, 0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // pruning
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += matchsticks[i];
        }
        if(sum % 4 != 0)
            return false;
        return dfs(matchsticks, n, sideLength, 0, sum / 4);
    }
}; 