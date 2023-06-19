class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int ans = 0;
        int altitude = 0;
        for(int i = 0; i < n; i++){
            altitude += gain[i];
            ans = max(ans, altitude);
        }
        return ans;
    }
};