class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // using bucket
        int ans = 0;
        vector<int> cnt(2e5, 0);
        for(int num: nums){
            cnt[num]++;
        }
        for(int num = 0; num < cnt.size(); num++){
            if(cnt[num] > 1){
                ans += cnt[num] - 1;
                cnt[num + 1] += cnt[num] - 1;
            }
        }
        return ans;
    }
};