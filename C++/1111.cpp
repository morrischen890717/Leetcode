class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // using math
        // time complexity: O(N)
        // reference: https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/solutions/328841/java-c-python-o-1-extra-space-except-output/
        int len = seq.length();
        vector<int> ans(len);
        for(int i = 0; i < len; i++){
            ans[i] = i & 1 ^ (seq[i] == '(');
        }
        return ans;
    }
};