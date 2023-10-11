class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // using sort(), upper_bound(), and lower_bound()
        // time complexity: O(NlogN + MlogN), where n == flowers.size() and M == people.size()
        // reference: https://leetcode.com/problems/number-of-flowers-in-full-bloom/solutions/1977099/c-python-binary-search-and-sweep-line/?envType=daily-question&envId=2023-10-11
        vector<int> ans(people.size());
        int n = flowers.size();
        vector<int> start(n), end(n);
        for(int i = 0; i < n; i++){
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for(int i = 0; i < people.size(); i++){
            int started = upper_bound(start.begin(), start.end(), people[i]) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), people[i]) - end.begin();
            ans[i] = started - ended;
        }
        return ans;
    }
};