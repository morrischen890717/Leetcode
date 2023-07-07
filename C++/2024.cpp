class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        // using two-pointers / sliding window
        int len = answerKey.length();
        int maxConsecutive = 0;
        vector<int> cnt(2, 0); // cnt[0] stands for the number of 'T', while cnt[1] stands for the number of 'F'
        int l = 0, r;
        for(r = 0; r < len; r++){
            int key = answerKey[r] == 'T' ? 0 : 1;
            cnt[key]++;
            int minCnt = min(cnt[0], cnt[1]);
            while(minCnt > k){
                maxConsecutive = max(maxConsecutive, r - l);
                int remove = answerKey[l] == 'T' ? 0 : 1;
                cnt[remove]--;
                minCnt = min(cnt[0], cnt[1]);
                l++;
            }
        }
        maxConsecutive = max(maxConsecutive, r - l);
        return maxConsecutive;
    }
};