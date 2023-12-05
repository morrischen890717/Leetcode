class Solution {
public:
    int numberOfMatches(int n) {
        // main idea: every match will decide a loser, one to win if and only if the other n-1 teams lose, so there are n-1 matches to get n-1 loser teams
        return n - 1;
    }
};