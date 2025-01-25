class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        // using sort
        int n = nums.size();
        vector<pair<int, int>> tmp;
        for(int i = 0; i < n; i++){
            tmp.push_back({nums[i], i});
        }
        sort(tmp.begin(), tmp.end());
        vector<int> idx = {tmp[0].second};
        int start = 0;
        for(int i = 1; i <= n; i++){
            if(i == n || abs(tmp[i].first - tmp[i - 1].first) > limit){
                sort(idx.begin(), idx.end());
                for(int j = start; j < i; j++){
                    nums[idx[j - start]] = tmp[j].first;
                }
                start = i;
                idx.clear();
            }
            if(i < n)
                idx.push_back(tmp[i].second);
        }
        return nums;
    }
};