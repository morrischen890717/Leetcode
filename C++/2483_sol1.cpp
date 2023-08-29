class Solution {
public:
    int bestClosingTime(string customers) {
        // using prefix sum
        // time complexity: O(N), space complexity: O(N), two pass
        int len = customers.length();
        vector<int> cnt(len, 0);
        cnt[0] = customers[0] == 'Y' ? 1 : 0;
        for(int i = 1; i < len; i++){
            cnt[i] = customers[i] == 'Y' ? cnt[i - 1] + 1 : cnt[i - 1];
        }
        int minPenalty = INT_MAX, closeDay = -1;
        for(int i = 0; i <= len; i++){
            int penalty = i == 0 ? cnt[len - 1] : (i - cnt[i - 1]) + (cnt[len - 1] -  cnt[i - 1]);
            if(penalty < minPenalty){
                minPenalty = penalty;
                closeDay = i;
            }
        }
        return closeDay;
    }
};