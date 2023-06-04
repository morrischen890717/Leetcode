class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        using binary search
        Time Complexity: O(log(min(n1, n2)))
        reference: https://leetcode.com/problems/median-of-two-sorted-arrays/solutions/2471/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation/
        */
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 < n2)
            return findMedianSortedArrays(nums2, nums1);
        int low = 0, high = n2 * 2;
        while(low <= high){
            int mid2 = (low + high) / 2;
            int mid1 = n1 + n2 - mid2;
            int L1 = (mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2]);
            int L2 = (mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2]);
            int R1 = (mid1 == n1 * 2 ? INT_MAX : nums1[mid1 / 2]);
            int R2 = (mid2 == n2 * 2 ? INT_MAX : nums2[mid2 / 2]);
            if(L1 > R2)
                low = mid2 + 1;
            else if(L2 > R1)
                high = mid2 - 1;
            else
                return (double)(max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};