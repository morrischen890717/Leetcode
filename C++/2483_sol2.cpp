class Solution {
public:
    int bestClosingTime(string customers) {
        // using prefix sum and suffix
        // time complexity: O(N), space complexity: O(N), one pass
        int len = customers.length();
        int minPenalty = INT_MAX, closeDay = -1;
        vector<int> cnt_n(len + 1, 0), cnt_y(len + 1, 0); // cnt_n[i] counts # of 'N' from [0, i], cnt_y[i] counts # of 'Y' from [i, len - 1]
        cnt_n[0] = customers[0] == 'N' ? 1 : 0;
        cnt_y[len - 1] = customers[len - 1] == 'Y' ? 1 : 0;
        for(int i = 1; i < len; i++){
            cnt_n[i] = customers[i] == 'N' ? cnt_n[i - 1] + 1 : cnt_n[i - 1];
            cnt_y[len - 1 - i] = customers[len - 1 - i] == 'Y' ? cnt_y[len - 1 - i + 1] + 1 : cnt_y[len - 1 - i + 1];
            if(i >= len / 2){
                if(cnt_n[i - 1] + cnt_y[i] < minPenalty){
                    minPenalty = cnt_n[i - 1] + cnt_y[i];
                    closeDay = i;
                }
                if(i != len - 1 && cnt_n[len - 1 - i - 1] + cnt_y[len - 1 - i] <= minPenalty){
                    minPenalty = cnt_n[len - 1 - i - 1] + cnt_y[len - 1 - i];
                    closeDay = len - 1 - i;
                }
            }
        }
        if(cnt_n[len - 1] < minPenalty){
            minPenalty = cnt_n[len - 1];
            closeDay = len;
        }
        if(cnt_y[0] <= minPenalty){
            minPenalty = cnt_y[0];
            closeDay = 0;
        }
        return closeDay;
    }
};