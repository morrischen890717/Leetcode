class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> table;
        int ans = 0, base = 0;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(table.count(s[i]) > 0 && table[s[i]] >= base){
                ans = max(ans, i - base);
                base = table[s[i]] + 1;
                table[s[i]] = i;
            }
            else{
                table[s[i]] = i;
            }
        }
        ans = max(ans, n - base);
        return ans;
    }
};