class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // using bottom-up DP
        // time complexity: O(N^2), space complexity: O(N)
        int n = books.size();
        vector<int> dp(n, INT_MAX);
        for(int i = 0; i < n; i++){
            int w = 0, h = 0;
            for(int j = i; j >= 0 && w + books[j][0] <= shelfWidth; j--){
                w += books[j][0];
                h = max(h, books[j][1]);
                dp[i] = j == 0 ? min(dp[i], h) : min(dp[i], dp[j - 1] + h);
            }
        }
        return dp[n - 1];
    }
};