class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        // using two-pointers
        // time complexity: O(NlogN), space complexity: O(N)
        // reference: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/solutions/5901109/beats-100-tc-sc-simple-and-easy-to-understand-python-cpp-java/?envType=daily-question&envId=2024-10-12
        int n = intervals.size();
        vector<int> start, end;
        for(vector<int>& interval: intervals){
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int end_ptr = 0, group = 0;
        for(int startTime: start){
            if(startTime > end[end_ptr])
                end_ptr++;
            else
                group++;
        }
        return group;
    }
};