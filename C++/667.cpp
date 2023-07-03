class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ans(n);
        ans[0] = 1;
        int id = 1;
        int sign = 1, diff = n - 1;
        /*
        the first (k-1) |diff|, will be (n-1), (n-2), ..., (n-k), which means the first (k-1) element in answer will be [1, n, 2, n - 1, 3, n - 2, ...]
        And the rest of elements in answer will be |diff| = 1
        */
        while(k > 1){
            ans[id] = ans[id - 1] + sign * diff;
            diff--;
            sign = -sign;
            id++;
            k--;
        }
        diff = 1;
        for(; id < n; id++){
            ans[id] = ans[id - 1] + sign * diff;
        }
        return ans;
    }
};