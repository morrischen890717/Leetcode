class Solution {
public:
    char convert(char c){
        if(c >= 'a' && c <= 'z')
            return 'A' + (c - 'a');
        return 'a' + (c - 'A');
    }
    void solve(int len, int i, vector<string>& ans){
        if(i >= len)
            return;
        if(!isdigit(ans[0][i])){
            int size = ans.size();
            for(int j = 0; j < size; j++){
                string s = ans[j];
                s[i] = convert(s[i]);
                ans.push_back(s);
            }
        }
        solve(len, i + 1, ans);
        return;
    }
    vector<string> letterCasePermutation(string s) {
        int len = s.length();
        vector<string> ans;
        ans.push_back(s);
        solve(len, 0, ans);
        return ans;
    }
};