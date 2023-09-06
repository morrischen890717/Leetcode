class Solution {
public:
    int clumsy(int n) {
        // time complexity: O(N), space complexity: O(1)
        int ans = 0;
        int op = 0, k = n;
        for(n--; n >= 1; n--, op = (op + 1) % 4){
            if(op == 0)
                k *= n;
            else if(op == 1)
                k /= n;
            else if(op == 2){
                ans += (k + n);
                k = 0;
            }
            else
                k = -n;
        }
        ans += k;
        return ans;
    }
};