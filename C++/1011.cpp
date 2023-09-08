class Solution {
public:
    bool check(vector<int>& weights, int capacity, int days){
        int sum = 0;
        for(int w: weights){
            if(w > capacity)
                return false;
            if(sum + w > capacity){
                days--;
                if(days < 0)
                    return false;
                sum = 0;
            }
            sum += w;
        }
        days--;
        return days < 0 ? false : true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // using binary search
        int sum = 0;
        for(int w: weights){
            sum += w;
        }
        int r = sum, l = sum / days + (sum % days ? 1 : 0);
        while(l <= r){ // binary search
            int mid = l + (r - l) / 2;
            if(check(weights, mid, days))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};