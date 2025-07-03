class Solution {
public:
    char solve(int k){
        if(k == 0)
            return 'a';
        int i = 1;
        while(i * 2 <= k){
            i *= 2;
        }
        return (solve(k % i) + 1 - 'a') % 26 + 'a';
    }
    char kthCharacter(int k) {
        k--;
        return solve(k);
    }
};