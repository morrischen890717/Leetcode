class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end(), cmp);
        int end = INT_MIN;
        int ans = 0;
        for(vector<int> p: pairs){
            if(end < p[0]){
                end = p[1];
                ans++;
            }
        }
        return ans;
    }
};