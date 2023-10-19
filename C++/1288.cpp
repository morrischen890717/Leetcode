class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // using sort()
        // time complexity: O(NlogN)
        sort(intervals.begin(), intervals.end());
        int max_left = -1, max_right = 0, cnt = 0;
        for(vector<int>& interval: intervals){
            if(interval[1] > max_right){
                if(interval[0] > max_left){
                    cnt++;
                    max_left = interval[0];
                }
                max_right = interval[1];
            }       
        }
        return cnt;
    }
};