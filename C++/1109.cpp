class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // using bucket and prefix sum
        // time complexity: O(N), space complexity: O(N)
        vector<int> ans(n);
        vector<int> cnt(n + 1, 0);
        for(vector<int>& book: bookings){
            cnt[book[0] - 1] += book[2];
            cnt[book[1]] -= book[2];
        }
        int seat = 0;
        for(int i = 0; i < n; i++){
            seat += cnt[i];
            ans[i] = seat;
        }
        return ans;
    }
};