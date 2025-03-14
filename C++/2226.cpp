class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // using binary search
        int n = candies.size();
        int l = 1, r = *max_element(candies.begin(), candies.end());
        while(l <= r){
            int mid = l + (r - l) / 2;
            long long cnt = 0;
            for(int num: candies){
                cnt += num / mid;
            }
            if(cnt >= k)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return r;
    }
};