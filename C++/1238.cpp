class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        /*
        using math and Gray code
        reference:
        https://leetcode.com/problems/circular-permutation-in-binary-representation/solutions/414203/java-c-python-4-line-gray-code/
        https://cp-algorithms.com/algebra/gray-code.html
        */
        vector<int> ans(1 << n);
        for(int i = 0; i < (1 << n); i++){
            ans[i] = start ^ (i ^ (i >> 1));
        }
        return ans;
    }
};