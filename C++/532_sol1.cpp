class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, bool> m;
        unordered_set<int> s;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(m.count(nums[i]) > 0){
                if(k == 0)
                    s.insert(nums[i]);
                continue;
            }
            if(m.count(nums[i] + k) > 0)
                cnt++;
            if(m.count(nums[i] - k) > 0)
                cnt++;
            m[nums[i]] = true;
        }
        return cnt + s.size();
    }
};