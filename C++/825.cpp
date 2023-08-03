class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // using bucket
        // time complexity: O(N), where N == ages.size()
        int ans = 0;
        vector<int> cnt(121, 0);
        for(int age: ages){
            cnt[age]++;
        }
        for(int i = 1; i <= 120; i++){
            int base = 0.5 * i + 8;
            for(int j = base; j <= i; j++){
                ans += cnt[j] * (j == i ? cnt[i] - 1 : cnt[i]);
            }
        }
        return ans;
    }
};