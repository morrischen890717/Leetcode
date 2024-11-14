class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        // using binary search
        // reference: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/solutions/1563739/java-c-python-binary-search/?envType=daily-question&envId=2024-11-14
        int l = 1, r = 1e5;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cnt = 0;
            for(int q: quantities){
                cnt += (q + mid - 1) / mid;
            }
            if(cnt > n)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};