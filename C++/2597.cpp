class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/the-number-of-beautiful-subsets/solutions/3314361/python-house-robber-o-n/?envType=daily-question&envId=2024-05-23
        int n = nums.size();
        unordered_map<int, int> cnt;
        unordered_map<int, vector<int>> m;
        for(int num: nums){
            if(cnt.count(num) == 0)
                m[num % k].push_back(num);
            cnt[num]++;
        }
        int ans = 1;
        for(unordered_map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++){
            sort(it->second.begin(), it->second.end());
            int prev = 0, skip = 1, take = 0;
            for(int num: it->second){
                int count = pow(2, cnt[num]) - 1;
                int tmp = skip;
                skip = skip + take;
                take = num - prev == k ? count * tmp : count * (tmp + take);
                prev = num;
            }
            ans *= (skip + take);
        }
        return ans - 1;
    }
};