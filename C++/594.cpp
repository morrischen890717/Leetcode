class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int num: nums){
            cnt[num]++;
        }
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            if(cnt.count(it->first + 1))
                ans = max(ans, it->second + cnt[it->first + 1]);
        }
        return ans;
    }
};