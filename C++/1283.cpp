class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // using binary search
        int l = 1, r = 1e6;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int sum = 0;
            for(int num: nums){
                sum += num / mid + (num % mid ? 1 : 0);
            }
            if(sum > threshold)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};