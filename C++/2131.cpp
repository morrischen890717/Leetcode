class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int len = 0, n = words.size();
        int cnt = 0;
        unordered_map<string, int> m;
        for(string& word: words){
            string s;
            s += word[1];
            s += word[0];
            if(m.count(s)){
                if(s[0] == s[1])
                    cnt--;
                m[s]--;
                if(m[s] == 0)
                    m.erase(s);
                len += 4;
            }
            else{
                if(s[0] == s[1])
                    cnt++;
                m[word]++;
            }
        }
        return len + (cnt ? 2 : 0);
    }
};