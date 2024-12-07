class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0;
        unordered_set<int> s(banned.begin(), banned.end());
        for(int i = 1; i <= n; i++){
            if(maxSum < i)
                return cnt;
            if(!s.count(i)){
                cnt++;
                maxSum -= i;
            }
        }
        return cnt;
    }
};