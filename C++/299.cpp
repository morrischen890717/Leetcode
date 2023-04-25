class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cnt_s(10, 0);
        vector<int> cnt_g(10, 0);
        int n = secret.length();
        string ans;
        int a_num = 0, b_num = 0;
        for(int i = 0; i < n; i++){
            cnt_s[secret[i] - '0']++;
            cnt_g[guess[i] - '0']++;
        }
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                a_num++;
                cnt_s[secret[i] - '0']--;
                cnt_g[guess[i] - '0']--;
            }
        }
        for(int i = 0; i < 10; i++){  // not perfectly match
            b_num += min(cnt_s[i], cnt_g[i]);
        }
        ans = to_string(a_num) + 'A' + to_string(b_num) + 'B';
        return ans;
    }
};