class Solution {
public:
    int getGap(long a, long b, long n){
        int cnt = 0;
        while(a <= n){
            cnt += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        // using Trie
        // time complexity: O(logN), space complexity: O(1)
        // reference: https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/solutions/5818614/beats-100-easy-solutions/?envType=daily-question&envId=2024-09-22
        int num = 1;
        k--;
        while(k){
            int gap = getGap(num, num + 1, n);
            if(gap <= k){
                k -= gap;
                num++;
            }
            else{
                k--;
                num *= 10;
            }
        }
        return num;
    }
};