class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int cnt = 0, end = 0;
        sort(rectangles.begin(), rectangles.end());
        end = rectangles[0][2];
        for(int i = 1; i < rectangles.size(); i++){
            if(rectangles[i][0] >= end)
                cnt++;
            end = max(end, rectangles[i][2]);
        }
        if(cnt >= 2)
            return true;
        sort(rectangles.begin(), rectangles.end(), [&](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });
        end = rectangles[0][3];
        cnt = 0;
        for(int i = 1; i < rectangles.size(); i++){
            if(rectangles[i][1] >= end)
                cnt++;
            end = max(end, rectangles[i][3]);
        }
        return cnt >= 2;
    }
};