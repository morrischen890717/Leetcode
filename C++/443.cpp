class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string s;
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(chars[i] == chars[i - 1])
                cnt++;
            else{
                s += chars[i - 1];
                if(cnt > 1)
                    s += to_string(cnt);
                cnt = 1;
            }
        }
        s += chars[n - 1];
        if(cnt > 1)
            s += to_string(cnt);
        chars.clear();
        for(int i = 0; i < s.length(); i++){
            chars.push_back(s[i]);
        }
        return s.length();
    }
};