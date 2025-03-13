class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // time complexity: O(N + M), space complexity: O(N), where N == nums.size() and M == queries.size()
        // reference: https://leetcode.com/problems/zero-array-transformation-ii/solutions/6053366/c-line-sweep-without-binary-search-o-n-m-time/?envType=daily-question&envId=2025-03-13
        int n = nums.size();
        vector<int> cnt(n + 1, 0);
        int k = 0, sum = 0;
        for(int i = 0; i < n; i++){
            while(sum + cnt[i] < nums[i]){
                if(k == queries.size())
                    return -1;
                int l = queries[k][0], r = queries[k][1], val = queries[k][2];
                k++;
                if(r < i)
                    continue;
                cnt[max(l, i)] += val;
                cnt[r + 1] -= val;
            }
            sum += cnt[i];
        }
        return k;
    }
};