class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // using two-pointers
        // time complexity: O(N1 + N2), space complexity: O(1), where N1 = nums1.size() and N2 == nums2.size()
        int n1 = nums1.size(), n2 = nums2.size();
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < n1 && ptr2 < n2 && nums1[ptr1] != nums2[ptr2]){
            if(nums1[ptr1] < nums2[ptr2])
                ptr1++;
            else
                ptr2++;
        }
        return ptr1 < n1 && ptr2 < n2 ? nums1[ptr1] : -1;
    }
};