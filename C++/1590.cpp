class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> prefix(n, 0);
        for(int i = 0; i < n; i++){
            prefix[i] = (i > 0 ? prefix[i - 1] : 0) + nums[i];
            prefix[i] %= p;
        }
        int sumMod = prefix.back() % p;
        if(sumMod == 0)
            return 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for(int i = 0; i < n; i++){
            int curMod = prefix[i] % p;
            int targetMod = (curMod + p - sumMod) % p;
            if(m.count(targetMod))
                ans = min(ans, i - m[targetMod]);
            m[curMod] = i;
        }
        return ans >= n ? -1 : ans;
    }
};