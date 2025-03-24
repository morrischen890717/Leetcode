class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0;
        sort(meetings.begin(), meetings.end());
        int farthest = 0;
        for(vector<int>& meeting: meetings){
            int start = meeting[0], end = meeting[1];
            if(start > farthest + 1)
                ans += start - (farthest + 1);
            farthest = max(farthest, end);
        }
        ans += days - farthest;
        return ans;
    }
};