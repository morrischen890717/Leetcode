class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        vector<int> ordered(heights.begin(), heights.end());
        sort(ordered.begin(), ordered.end());
        for(int i = 0; i < n; i++){
            if(heights[i] != ordered[i])
                ans++;
        }
        return ans;
    }
};