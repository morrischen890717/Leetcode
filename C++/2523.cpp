class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        int prev = -1, diff = INT_MAX;
        vector<int> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= right; i++){
            if(isPrime[i]){
                for(int j = i * 2; j <= right; j += i){
                    isPrime[j] = false;
                }
            }
        }
        for(int i = left; i <= right; i++){
            if(isPrime[i]){
                if(prev != -1 && i - prev < diff){
                    diff = i - prev;
                    ans = {prev, i};
                }
                prev = i;
            }
        }
        return ans;
    }
};