class Solution {
public:
    int maximumLength(string s) {
        int ans = 0;
        s += ' ';
        vector<pair<int, int>> max_len(26, {0, 0}); // {len, appearance times}
        char prev = '.';
        int len = 0;
        for(char c: s){
            if(c == prev)
                len++;
            else{
                if(prev != '.'){
                    ans = max(ans, len - 2);
                    if(len == max_len[prev - 'a'].first)
                        max_len[prev - 'a'].second++;
                    else if(len > max_len[prev - 'a'].first)
                        max_len[prev - 'a'].second += 2;
                    else
                        ans = max(ans, len);
                    if(max_len[prev - 'a'].second >= 3)
                        ans = max(ans, max_len[prev - 'a'].first);
                    else if(max_len[prev - 'a'].second == 2)
                        ans = max(ans, max_len[prev - 'a'].first - 1);
                    if(len > max_len[prev - 'a'].first)
                        max_len[prev - 'a'] = {len, 1};
                }
                len = 1;
                prev = c;
            }
        }
        return ans == 0 ? -1 : ans;
    }
};