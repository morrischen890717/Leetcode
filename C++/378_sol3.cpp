class Solution {
public:
    int lessAndEqualNumber(vector<vector<int>>& matrix, int target){
        int m = matrix.size(), n = matrix[0].size();
        int ptr = n - 1;
        int cnt = 0;
        for(int i = 0; i < m; i++){
            while(ptr >= 0 && matrix[i][ptr] > target)
                ptr--;
            cnt += (ptr + 1);
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        /*
        using binary search
        time complexity: O((m + n) * logD), where D is the difference between the maximum element and the minimum element in the matrix
        ( m+n is for counting, and logD is for binary search )
        space complexity: O(1)
        reference: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/1322101/c-java-python-maxheap-minheap-binary-search-picture-explain-clean-concise/
        */
        int m = matrix.size(), n = matrix[0].size();
        int l = matrix[0][0], r = matrix[m - 1][n - 1];
        int ans;
        while(l <= r){
            int mid = (l + r) / 2;
            int cnt = lessAndEqualNumber(matrix, mid);
            if(cnt >= k){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};