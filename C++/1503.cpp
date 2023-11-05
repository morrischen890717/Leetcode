class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        // using math
        // reference: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/solutions/720189/java-c-python-ants-keep-walking-o-n/?envType=daily-question&envId=2023-11-04
        int ans = 0;
        for(int pos: left){
            ans = max(ans, pos);
        }
        for(int pos: right){
            ans = max(ans, n - pos);
        }
        return ans;
    }
};