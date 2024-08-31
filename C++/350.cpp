class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        vector<int> cnt(1001, 0);
        for(int num: nums1){
            cnt[num]++;
        }
        for(int num: nums2){
            if(cnt[num]){
                cnt[num]--;
                ans.push_back(num);
            }
        }
        return ans;
    }
};