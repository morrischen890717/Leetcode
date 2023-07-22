class Solution {
public:
    int solve(int k){
        if(k == 0)
            return 0;
        int prev = solve(k / 2); // the number of the previous row
        if(prev)
            return k % 2 ? 0 : 1;
        return k % 2 ? 1 : 0;
    }
    int kthGrammar(int n, int k) {
        // time complexity: O(logK)
        k--; // change k from 1-indexed to 0-indexed to make it easier to compute
        return solve(k);
    }
};