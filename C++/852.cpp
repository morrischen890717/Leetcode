class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // using binary search
        // time complexity: O(logN)
        int n = arr.size();
        int l = 1, r = n - 2;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if(arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1])
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
};