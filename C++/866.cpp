class Solution {
public:
    bool isPrime(int x){
        if(x == 1)
            return false;
        for(int i = 2; i <= sqrt(x); i++){
            if(x % i == 0)
                return false;
        }
        return true;
    }
    int primePalindrome(int n) {
        /*
        using math
        main idea: the length of answers expect for 11 will be odd number (if the length of the answer(except for 11) is even, it is divisible by 11)
        reference: https://leetcode.com/problems/prime-palindrome/solutions/146798/java-c-python-all-even-length-palindrome-are-divisible-by-11/
        */
        if(n >= 8 && n <= 11)
            return 11;
        for(int i = 1; i < 20000; i++){
            string prefix = to_string(i);
            string suffix(prefix.rbegin(), prefix.rend());
            int x = stoi(prefix + suffix.substr(1));
            if(x >= n && isPrime(x))
                return x;
        }
        return -1;
    }
};