class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // using Greedy
        // time complexity: O(N)
        vector<int> ans = {1};
        k--;
        int sign = -1;
        int d = n;
        /*
        the first (k-1) |diff|, will be (n-1), (n-2), ..., (n-k), which means the first (k-1) element in answer will be [1, n, 2, n - 1, 3, n - 2, ...]
        And the rest of elements in answer will be |diff| = 1
        */
        for(int i = 0; i < n - 1; i++){
            if(k >= 0){
                sign = -sign;
                d = k == 0 ? 1 : d - 1;
                k--;
            }
            ans.push_back(ans.back() + sign * d);
        }
        return ans;
    }
};