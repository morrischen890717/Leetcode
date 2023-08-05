class Solution {
public:
    void add(char c, int len, string& s){
        for(int i = 0; i < len; i++){
            s += c;
        }
        return;
    }
    string pushDominoes(string dominoes) {
        // using two-pointers
        dominoes += 'R';
        int len = dominoes.length();
        string ans;
        char prev = 'L';
        int prevId = -1;
        for(int i = 0; i < len; i++){
            if(dominoes[i] == '.')
                continue;
            if(prev == 'L' && dominoes[i] == 'L')
                add('L', i - prevId - 1, ans);
            else if(prev == 'L' && dominoes[i] == 'R')
                add('.', i - prevId - 1, ans);
            else if(prev == 'R' && dominoes[i] == 'L'){
                add('R', (i - prevId - 1) / 2, ans);
                add('.', (i - prevId - 1) % 2, ans);
                add('L', (i - prevId - 1) / 2, ans);
            }
            else if(prev == 'R' && dominoes[i] == 'R')
                add('R', i - prevId - 1, ans);
            if(i != len - 1)
                ans += dominoes[i];
            prev = dominoes[i];
            prevId = i;
        }
        return ans;
    }
};