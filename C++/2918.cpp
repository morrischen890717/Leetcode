class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for(int num: nums1){
            sum1 += num == 0 ? 1 : num;
            if(num == 0)
                cnt1++;
        }
        for(int num: nums2){
            sum2 += num == 0 ? 1 : num;
            if(num == 0)
                cnt2++;
        }
        long long res = max(sum1, sum2);
        if(sum1 < res && cnt1 == 0 || sum2 < res && cnt2 == 0)
            return -1;
        return res;
    }
};