class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
        using two pointers
        time complexity: O(N - k)
        */
        int n = arr.size();
        int l = 0, r = n - 1;
        while(n > k){ // keep removing the farest element until k elements left
            int diff_l = abs(x - arr[l]), diff_r = abs(x - arr[r]);
            if(diff_l > diff_r)
                l++;
            else
                r--;
            n--;
        }
        vector<int> ans(arr.begin() + l, arr.begin() + r + 1);
        return ans;
    }
};