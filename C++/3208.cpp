class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ans = 0;
        int n = colors.size(), cnt = 0, prev = -1;
        for(int i = 0; i < n + k - 1; i++){
            if(colors[i % n] == prev)
                cnt = 1;
            else
                cnt++;
            prev = colors[i % n];
            if(cnt >= k)
                ans++;
        }
        return ans;
    }
};