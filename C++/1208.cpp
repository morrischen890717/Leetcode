class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // using two-pointers and sliding window
        // time complexity: O(N), space complexity: O(1)
        int ans = 0;
        int len = s.length();
        int cost = 0;
        int l = 0;
        for(int r = 0; r < len; r++){
            cost += abs(s[r] - t[r]);
            while(cost > maxCost){
                cost -= abs(s[l] - t[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};