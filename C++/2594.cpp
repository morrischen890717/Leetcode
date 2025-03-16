class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        long long l = 0, r = (long long)100 * cars * cars;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            int cnt = 0;
            for(int i = 0; i < n && cnt < cars; i++){
                cnt += sqrt(mid / ranks[i]);
            }
            if(cnt >= cars)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};