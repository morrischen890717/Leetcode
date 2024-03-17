class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back({INT_MAX, INT_MAX});
        vector<vector<int>> ans;
        for(vector<int>& interval: intervals){
            if(newInterval[0] == INT_MAX || interval[1] < newInterval[0]) // newInterval[0] == INT_MAX means that we have already inserted the merged newInterval, so we only need to insert the rest of the intervals
                ans.push_back(interval);
            else if(interval[0] > newInterval[1]){
                ans.push_back(newInterval);
                newInterval = {INT_MAX, INT_MAX};
                ans.push_back(interval);
            }
            else
                newInterval = {min(newInterval[0], interval[0]), max(newInterval[1], interval[1])};
        }
        ans.pop_back();
        return ans;
    }
};