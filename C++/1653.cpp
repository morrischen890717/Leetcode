class Solution {
public:
    int minimumDeletions(string s) {
        // using DP
        // time complexity: O(N), space complexity: O(1)
        int cnt_b = 0, ans = 0;
        for(char c: s){
            if(c == 'b')
                cnt_b++;
            else
                ans = min(ans + 1, cnt_b);
        }
        return ans;
    }
};