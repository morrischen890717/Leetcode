class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        // using two-pointers
        vector<bool> ans(queries.size(), true);
        for(int i = 0; i < queries.size(); i++){
            int ptr = 0;
            for(int j = 0; j < queries[i].length(); j++){
                if(ptr < pattern.length() && queries[i][j] == pattern[ptr]){
                    ptr++;
                }
                else if(isupper(queries[i][j]))
                    ans[i] = false;
            }
            ans[i] = ptr < pattern.length() ? false : ans[i];
        }
        return ans;
    }
};