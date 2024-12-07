class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // using binary search
        int l = 1, r = INT_MAX;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cnt = 0;
            bool valid = true;
            for(int num: nums){
                if(num < mid + 1)
                    continue;
                cnt += num / mid + (num % mid ? 0 : -1);
                if(cnt > maxOperations){
                    valid = false;
                    break;
                }
            }
            if(valid)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};