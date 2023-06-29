class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        /*
        using binary search
        time complexity: O(log(N - k))
        */
        int n = arr.size();
        int l = 0, r = n - 1 - k;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(x - arr[mid] > arr[mid + k] - x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        vector<int> ans(arr.begin() + l, arr.begin() + l + k);
        return ans;
    }
};