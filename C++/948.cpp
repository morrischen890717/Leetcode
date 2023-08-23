class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // using sort(), two-pointers, and Greedy
        // time complexity: O(NlogN), space complexity: O(1)
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), l = 0, r = n - 1;
        int ans = 0, score = 0;
        while(l <= r){
            if(power >= tokens[l]){
                score++;
                power -= tokens[l];
                ans = max(ans, score);
                l++;
            }
            else if(score){
                score--;
                power += tokens[r];
                r--;
            }
            else
                break;
        }
        return ans;
    }
};