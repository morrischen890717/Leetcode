class Solution {
public:
    int countPrimes(int n) {
        /*
        reference: https://leetcode.com/problems/count-primes/solutions/1200796/js-python-java-c-easy-sieve-of-eratosthenes-solution-w-explanation/?envType=featured-list&envId=top-interview-questions
        */
        vector<bool> prime(n, true);
        int cnt = 0;
        for(int i = 2; i < n; i++){
            if(prime[i]){
                cnt++;
                /*
                We start at num^2 because every multiple up to the num'th multiple will have been guaranteed to have been seen before, 
                since they're also a multiple of a smaller number.
                */
                for(long long j = (long long)i * i; j < n; j += i){
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};