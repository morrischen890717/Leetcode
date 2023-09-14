class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        // using sort and two-pointers
        // time complexity: O(NlogN)
        // reference: https://leetcode.com/problems/moving-stones-until-consecutive-ii/solutions/286707/java-c-python-sliding-window/
        int n = stones.size();
        vector<int> ans(2, INT_MAX);
        sort(stones.begin(), stones.end());
        ans[1] = max(stones[n - 1] - stones[1] - n + 2, stones[n - 2] - stones[0] - n + 2);
        int l = 0;
        for(int r = 0; r < n; r++){
            while(stones[r] - stones[l] + 1 > n){
                l++;
            }
            if(r - l + 1 == n - 1 && stones[r] - stones[l] + 1 == n - 1)
                ans[0] = min(ans[0], 2);
            else
                ans[0] = min(ans[0], n - (r - l + 1));
        }
        return ans;
    }
};