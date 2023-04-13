class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int start, end;
        vector<int> max_end = intervals[0];
        for(int i = 1; i < intervals.size(); i++){
            start = intervals[i][0];
            end = intervals[i][1];
            if(start > max_end[1]){
                result.push_back(max_end);
                max_end = intervals[i];
            }
            else{
                max_end[1] = max(max_end[1], end);
            }
        }
        result.push_back(max_end);
        return result;
    }
};