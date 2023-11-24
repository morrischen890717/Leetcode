class Solution {
public:
    int maxCoins(vector<int>& piles) {
        // using sort
        int ans = 0;
        int n = piles.size();
        sort(piles.begin(), piles.end());
        for(int i = n / 3; i < n; i += 2){
            ans += piles[i];
        }
        return ans;
    }
};