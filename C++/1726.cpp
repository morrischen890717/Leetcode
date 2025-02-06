class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int, int> cnt;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                cnt[nums[i] * nums[j]]++;
            }
        }
        for(unordered_map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans += it->second * (it->second - 1) / 2 * 8;
        }
        return ans;
    }
};