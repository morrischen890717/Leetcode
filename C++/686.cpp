class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        /*
        using Knuth–Morris–Pratt Algorithm (KMP Algorithm)
        time complexity: O(N + M), where N = a.length() and M = b.length()
        reference:
        https://yeefun.github.io/kmp-algorithm-for-beginners/
        https://leetcode.com/problems/repeated-string-match/solutions/108084/c-4-lines-o-m-n-o-1-and-kmp-o-m-n-o-n/
        */
        int len1 = a.length(), len2 = b.length();
        vector<int> next(len2, 0);
        int suffixId = 1, prefixId = 0;
        while(suffixId < len2){ // create next table, time complexity: O(M)
            if(b[suffixId] == b[prefixId]){
                suffixId++;
                prefixId++;
                next[suffixId - 1] = prefixId;
            }
            else if(prefixId == 0){
                suffixId++;
                next[suffixId - 1] = 0;
            }
            else
                prefixId = next[prefixId - 1];
        }

        int i = 0, j = 0;
        while(i < len1){ // time complexity: O(N)
            while(j < len2 && a[(i + j) % len1] == b[j]){
                j++;
            }
            if(j == len2)
                return (i + (len2 - 1)) / len1 + 1;
            if(j == 0)
                i++;
            else{
                i = i + j - next[j - 1]; // let next iteration's (i+j) keeps the same as current iteration's (i+j)
                j = next[j - 1];
            }
        }
        return -1;
    }
};