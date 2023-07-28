class Solution {
public:
    void merge(vector<int>& nums, vector<int>& id, int start, int mid, int end, vector<int>& counts){
        vector<int> left(id.begin() + start, id.begin() + mid + 1);
        vector<int> right(id.begin() + mid + 1, id.begin() + end + 1);
        int ptrLeft = 0, ptrRight = 0;
        int pos = start;
        while(ptrLeft < left.size() && ptrRight < right.size()){
            if(nums[left[ptrLeft]] > nums[right[ptrRight]]){
                counts[left[ptrLeft]] += (right.size() - ptrRight);
                id[pos] = left[ptrLeft];
                ptrLeft++;
            }
            else{
                id[pos] = right[ptrRight];
                ptrRight++;
            }
            pos++;
        }
        while(ptrLeft < left.size()){
            id[pos] = left[ptrLeft];
            ptrLeft++;
            pos++;
        }
        while(ptrRight < right.size()){
            id[pos] = right[ptrRight];
            ptrRight++;
            pos++;
        }
        return;
    }
    void mergeSort(vector<int>& nums, vector<int>& id, int start, int end, vector<int>& counts){
        if(start < end){
            int mid = (start + end) / 2;
            mergeSort(nums, id, start, mid, counts);
            mergeSort(nums, id, mid + 1, end, counts);
            merge(nums, id, start, mid, end, counts);
        }
        return;
    }
    vector<int> countSmaller(vector<int>& nums) {
        // using merge sort
        // time complexity: O(NlogN)
        // reference: https://alrightchiu.github.io/SecondRound/comparison-sort-merge-sorthe-bing-pai-xu-fa.html
        int n = nums.size();
        vector<int> counts(n, 0);
        vector<int> id(n);
        for(int i = 0; i < n; i++){
            id[i] = i;
        }
        mergeSort(nums, id, 0, n - 1, counts);
        return counts;
    }
};