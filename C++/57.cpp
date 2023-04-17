class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int insert_id = 0, erase_s = -1, erase_e = -2;
        int new_s = newInterval[0], new_e = newInterval[1];
        for(int i = 0; i < n; i++){
            if(newInterval[0] >= intervals[i][0] && newInterval[0] <= intervals[i][1]){
                new_s = intervals[i][0];
                insert_id = erase_s = i;
            }
            else if(i == 0 && newInterval[0] < intervals[i][0]){
                new_s = newInterval[0];
                insert_id = erase_s = i;
            }
            else if((i == n - 1 && newInterval[0] > intervals[i][1]) || (newInterval[0] > intervals[i][1] && newInterval[0] < intervals[i + 1][0])){
                new_s = newInterval[0];
                insert_id = erase_s = i + 1;
            }
            if(newInterval[1] >= intervals[i][0] && newInterval[1] <= intervals[i][1]){
                new_e = intervals[i][1];
                erase_e = i;
                break;
            }
            else if(i == 0 && newInterval[1] < intervals[i][1]){
                new_e = newInterval[1];
                erase_e = -3;
                break;
            }
            else if((i == n - 1 && newInterval[1] > intervals[i][1]) || (newInterval[1] > intervals[i][1] && newInterval[1] < intervals[i + 1][0])){
                new_e = newInterval[1];
                erase_e = i;
                break;
            }
        }
        if(erase_s <= erase_e)
            intervals.erase(intervals.begin() + erase_s, intervals.begin() + erase_e + 1);
        intervals.insert(intervals.begin() + insert_id, {new_s, new_e});
        return intervals;
    }
};