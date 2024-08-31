class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        // using binary search
        int n = bloomDay.size();
        if(n < (long long)m * k)
            return -1;
        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cnt_k = 0, cnt_m = 0;
            for(int i = 0; i < n && cnt_m < m; i++){
                if(bloomDay[i] <= mid)
                    cnt_k++;
                else
                    cnt_k = 0;
                if(cnt_k == k){
                    cnt_m++;
                    cnt_k = 0;
                }
            }
            if(cnt_m == m)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};