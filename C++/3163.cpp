class Solution {
public:
    string compressedString(string word) {
        string ans;
        char prev = word[0];
        int cnt = 0;
        for(char c: word){
            if(c != prev || cnt == 9){
                ans += '0' + cnt;
                ans += prev;
                prev = c;
                cnt = 1;
            }
            else
                cnt++;
        }
        ans += '0' + cnt;
        ans += prev;
        return ans;
    }
};