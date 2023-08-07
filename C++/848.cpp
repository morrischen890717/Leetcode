class Solution {
public:
    char shift(char c, int move){
        return (c + move - 'a') % 26 + 'a';
    }
    string shiftingLetters(string s, vector<int>& shifts) {
        // time complexity: O(N), space complexity: O(1)
        int len = s.length();
        int suffix = 0;
        for(int i = len - 1; i >= 0; i--){
            shifts[i] += suffix;
            shifts[i] %= 26;
            suffix = shifts[i];
        }
        for(int i = 0; i < len; i++){
            s[i] = shift(s[i], shifts[i]);
        }
        return s;
    }
};