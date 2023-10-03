class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for(int num: nums){
            ans += cnt[num];
            cnt[num]++;
        }
        return ans;
    }
};