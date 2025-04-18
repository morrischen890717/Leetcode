class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int repeat = 0;
        unordered_map<int, int> cnt;
        for(int num: nums){
            if(cnt.count(num) && cnt[num] == 1)
                repeat++;
            cnt[num]++;
        }
        int l = 0;
        while(repeat){
            for(int i = 0; i < 3 && l < n; i++, l++){
                cnt[nums[l]]--;
                if(cnt[nums[l]] == 1)
                    repeat--;
            }
            ans++;
        }
        return ans;
    }
};