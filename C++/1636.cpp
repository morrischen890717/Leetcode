class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<int> cnt(201, 0);
        for(int num: nums){
            cnt[num + 100]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            return cnt[a + 100] == cnt[b + 100] ? a > b : cnt[a + 100] < cnt[b + 100];
        });
        return nums;
    }
};