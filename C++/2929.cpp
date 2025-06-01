class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(limit, n); i++){
            if(n - i > 2 * limit)
                continue;
            else if(n - i < limit)
                ans += n - i + 1;
            else
                ans += limit - (n - i - limit) + 1;
        }
        return ans;
    }
};