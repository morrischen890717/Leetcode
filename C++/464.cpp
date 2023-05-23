class Solution {
public:
    bool canWin(vector<char>& dp, int chosen, int maxChoosableInteger, int desiredTotal){
        if(dp[chosen] != 0)
            return dp[chosen] == 1;
        for(int i = 0; i < maxChoosableInteger; i++){
            if(chosen & (1 << i)) // this choice has been chosen before
                continue;
            if((i + 1) >= desiredTotal || !canWin(dp, chosen | (1 << i), maxChoosableInteger, desiredTotal - (i + 1))){ // canWin(...) represents whether player 2 can win after player 1 choose number (i+1)
                dp[chosen] = 1;
                return true;
            }
        }
        dp[chosen] = -1;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal)
            return false;
        vector<char> dp(1 << maxChoosableInteger, 0);
        return canWin(dp, 0, maxChoosableInteger, desiredTotal);
    }
};