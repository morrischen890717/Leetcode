class Solution {
public:
    string lcs(string& str1, string& str2){ // find longest common substring
        int len1 = str1.length(), len2 = str2.length();
        vector<vector<string>> dp(len1 + 1, vector<string> (len2 + 1, ""));
        for(int i = 0; i < len1; i++){
            for(int j = 0; j < len2; j++){
                if(str1[i] == str2[j])
                    dp[(i + 1) % 2][j + 1] = dp[i % 2][j] + str1[i];
                else
                    dp[(i + 1) % 2][j + 1] = dp[(i + 1) % 2][j].length() > dp[i % 2][j + 1].length() ? dp[(i + 1) % 2][j] : dp[i % 2][j + 1];
            }
        }
        return dp[len1 % 2][len2];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/shortest-common-supersequence/solutions/312710/c-python-find-the-lcs/?envType=daily-question&envId=2025-02-28
        string ans = "";
        int ptr1 = 0, ptr2 = 0;
        string res = lcs(str1, str2);
        for(char c: res){
            while(str1[ptr1] != c){
                ans += str1[ptr1++];
            }
            while(str2[ptr2] != c){
                ans += str2[ptr2++];
            }
            ans += c;
            ptr1++;
            ptr2++;
        }
        return ans + str1.substr(ptr1) + str2.substr(ptr2);
    }
};