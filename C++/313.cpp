class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        // time complexity: O(kN), space complexity: O(N), where N == n and k == primes.size()
        // reference: https://leetcode.com/problems/super-ugly-number/solutions/76291/java-three-methods-23ms-36-ms-58ms-with-heap-performance-explained/
        vector<long long> ugly(n, INT_MAX);
        int size = primes.size();
        vector<int> id(size, 0);
        ugly[0] = 1;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < size; j++){
                ugly[i] = min(ugly[i], ugly[id[j]] * primes[j]);
            }
            for(int j = 0; j < size; j++){
                while(ugly[id[j]] * primes[j] <= ugly[i])
                    id[j]++;
            }
        }
        return ugly[n - 1];
    }
};