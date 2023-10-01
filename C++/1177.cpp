class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // using bit manipulation and prefix sum
        int len = s.length();
        int n = queries.size();
        vector<bool> ans(n);
        vector<int> prefix(len, 0); // each bit represents the frequency of the char is odd or even
        for(int i = 0; i < len; i++){
            prefix[i] = ((i == 0 ? 0 : prefix[i - 1]) ^ (1 << (s[i] - 'a')));
        }
        for(int i = 0; i < n; i++){
            int left = queries[i][0], right = queries[i][1], k = queries[i][2];
            int odd = 0;
            int state = ((left == 0 ? 0 : prefix[left - 1]) ^ prefix[right]);
            for(int j = 0; j < 26; j++){
                if(state & (1 << j))
                    odd++;
            }
            ans[i] = odd / 2 <= k;
        }
        return ans;
    }
};