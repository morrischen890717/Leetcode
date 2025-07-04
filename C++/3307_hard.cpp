class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        // reference: https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/solutions/5846414/java-c-python-6-line-o-logk/?envType=daily-question&envId=2025-07-04
        int res = 0;
        int n = operations.size();
        k--;
        for(int i = 0; i < n && i < 60; i++){
            if((k >> i) & 1)
                res += operations[i];
        }
        return 'a' + res % 26;
    }
};