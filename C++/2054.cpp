class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // using sort and Greedy
        // reference: https://leetcode.com/problems/two-best-non-overlapping-events/solutions/1552570/very-simple-sort-greedy-no-dp-no-binary-search-no-heap-pq-bst/?envType=daily-question&envId=2024-12-08
        int ans = 0, max_val = 0;
        vector<vector<int>> v;
        for(vector<int>& event: events){
            v.push_back({event[0], 0, event[2]});
            v.push_back({event[1], 1, event[2]});
        }
        sort(v.begin(), v.end());
        for(vector<int>& tmp: v){
            if(tmp[1] == 0)
                ans = max(ans, max_val + tmp[2]);
            else
                max_val = max(max_val, tmp[2]);
        }
        return ans;
    }
};