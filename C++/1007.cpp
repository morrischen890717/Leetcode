class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // using Greedy
        // time complexity: O(N), space complexity: O(1)
        int n = tops.size();
        int cnt1Top = 0, cnt1Bottom = 0, cnt2Top = 0, cnt2Bottom = 0;
        int candidate1 = tops[0], candidate2 = bottoms[0];
        for(int i = 0; i < n; i++){
            if(tops[i] != candidate1 && bottoms[i] != candidate1)
                candidate1 = -1;
            if(tops[i] != candidate2 && bottoms[i] != candidate2)
                candidate2 = -1;
            cnt1Top = tops[i] == candidate1 ? cnt1Top + 1 : cnt1Top;
            cnt1Bottom = bottoms[i] == candidate1 ? cnt1Bottom + 1 : cnt1Bottom;
            cnt2Top = tops[i] == candidate2 ? cnt2Top + 1 : cnt2Top;
            cnt2Bottom = bottoms[i] == candidate2 ? cnt2Bottom + 1 : cnt2Bottom;
        }
        if(candidate1 != -1)
            return n - max(cnt1Top, cnt1Bottom);
        else if(candidate2 != -1)
            return n - max(cnt2Top, cnt2Bottom);
        return -1;
    }
};