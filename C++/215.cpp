class Solution {
public:
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[hi];
        int i = lo, j = hi - 1;
        while(i <= j){
            if(nums[j] > pivot){
                swap(nums[i], nums[j]);
                i++;
            }
            else
                j--;
        }
        swap(nums[i], nums[hi]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        /*
        using quick selection (similar to quick sort, but just costs O(N) time)
        the execution time will cost n + log(n) + log(log(n)) + ... + 1 < 2n
        (e.g. 16 > 8 + 4 + 2 + 1)
        thus, time complexity: O(2N) = O(N)
        reference: https://shubo.io/quick-sort/
        */
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while(true){
            int p = partition(nums, lo, hi);
            if(p == k - 1)
                return nums[k - 1];
            else if(p < k - 1)
                lo = p + 1;
            else
                hi = p - 1;
        }
        return -1;
    }
};