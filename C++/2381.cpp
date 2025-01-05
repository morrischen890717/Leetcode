class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int len = s.length();
        vector<int> start(len, 0), end(len, 0);
        for(vector<int>& shift: shifts){
            start[shift[0]] += shift[2] == 1 ? 1 : -1;
            end[shift[1]] += shift[2] == 1 ? 1 : -1;
        }
        int cur_shift = 0;
        for(int i = 0; i < len; i++){
            cur_shift += start[i];
            int move = cur_shift;
            move = move >= 0 ? move % 26 : 26 - (-move % 26);
            s[i] = 'a' + (s[i] - 'a' + move) % 26;
            cur_shift -= end[i];
        }
        return s;
    }
};