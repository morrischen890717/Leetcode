class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans(queries.size());
        int n = words.size();
        vector<int> cnts(12, 0);
        for(int i = 0; i < n; i++){
            char min_char = 'z';
            int cnt = 0;
            for(char c: words[i]){
                if(c < min_char){
                    min_char = c;
                    cnt = 1;
                }
                else if(c == min_char)
                    cnt++;
            }
            cnts[cnt]++;
        }
        for(int i = cnts.size() - 2; i >= 0; i--){
            cnts[i] += cnts[i + 1];
        }
        for(int i = 0; i < queries.size(); i++){
            char min_char = 'z';
            int cnt = 0;
            for(char c: queries[i]){
                if(c < min_char){
                    min_char = c;
                    cnt = 1;
                }
                else if(c == min_char)
                    cnt++;
            }
            ans[i] = cnts[cnt + 1];
        }
        return ans;
    }
};