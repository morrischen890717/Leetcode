class Solution {
public:
    int get_beauty(vector<int>& cnt, int x){
        int num = 0;
        for(int i = 0; i < 50; i++){
            num += cnt[i];
            if(num >= x)
                return i - 50;
        }
        return 0;
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        vector<int> cnt(50, 0);
        for(int i = 0; i < k; i++){
            if(nums[i] < 0)
                cnt[nums[i] + 50]++;
        }
        ans.push_back(get_beauty(cnt, x));
        for(int i = 1; i < n - k + 1; i++){
            if(nums[i - 1] < 0)
                cnt[nums[i - 1] + 50]--;
            if(nums[i + k - 1] < 0)
                cnt[nums[i + k - 1] + 50]++;
            ans.push_back(get_beauty(cnt, x));
        }
        
        return ans;
    }
};