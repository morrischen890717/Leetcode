class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int ans = 0;
        set<int> s;
        for(vector<int>& point: points){
            s.insert(point[0]);
        }
        for(set<int>::iterator it = next(s.begin()); it != s.end(); it++){
            ans = max(ans, *it - *prev(it));
        }
        return ans;
    }
};