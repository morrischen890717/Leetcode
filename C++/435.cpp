class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int ans = 0;
        int end = INT_MIN;
        sort(intervals.begin(), intervals.end(), cmp);
        for(int i = 0; i < n; i++){
            if(intervals[i][0] >= end)
                end = intervals[i][1];
            else
                ans++;
        }
        return ans;
    }
};