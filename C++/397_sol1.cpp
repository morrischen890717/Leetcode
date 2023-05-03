class Solution {
public:
    int recursion(long long n){
        if(n == 1)
            return 0;
        if(n % 2 == 0)
            return 1 + recursion(n / 2);
        else
            return 1 + min(recursion(n + 1), recursion(n - 1));
    }
    int integerReplacement(int n) {
        return recursion(n);
    }
};