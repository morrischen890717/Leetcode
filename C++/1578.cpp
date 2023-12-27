class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        int ans = 0;
        int len = colors.length();
        int cnt = 0, maxTime = INT_MIN, sumTime = 0;
        char prev = '.';
        for(int i = 0; i < len; i++){
            if(colors[i] == prev){
                cnt++;
                maxTime = max(maxTime, neededTime[i]);
                sumTime += neededTime[i];
            }
            else{
                if(cnt > 1)
                    ans += sumTime - maxTime;
                cnt = 1;
                maxTime = sumTime = neededTime[i];
                prev = colors[i];
            }
        }
        if(cnt > 1)
            ans += sumTime - maxTime;
        return ans;
    }
};