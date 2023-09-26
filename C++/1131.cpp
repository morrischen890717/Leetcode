class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        // using math
        // reference: https://leetcode.com/problems/maximum-of-absolute-value-expression/solutions/339968/java-c-python-maximum-manhattan-distance/
        int ans = 0;
        int n = arr1.size();
        for(int a: {-1, 1}){
            for(int b: {-1, 1}){
                int smallest = a * arr1[0] + b * arr2[0] + 0;
                for(int i = 1; i < n; i++){
                    int val = a * arr1[i] + b * arr2[i] + i;
                    ans = max(ans, val - smallest);
                    smallest = min(smallest, val);
                }
            }
        }
        return ans;
    }
};