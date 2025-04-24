class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int distinct = 0;
        unordered_map<int, int> cnt;
        for(int num: nums){
            if(!cnt.count(num)){
                distinct++;
                cnt[num] = 0;
            }
        }
        int l = 0;
        for(int r = 0; r < n; r++){
            cnt[nums[r]]++;
            if(cnt[nums[r]] == 1)
                distinct--;
            while(distinct == 0){
                ans += n - r;
                cnt[nums[l]]--;
                if(cnt[nums[l]] == 0)
                    distinct++;
                l++;
            }
        }
        return ans;
    }
};