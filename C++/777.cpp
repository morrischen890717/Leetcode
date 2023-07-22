class Solution {
public:
    bool canTransform(string start, string end) {
        /*
        using two-pointers
        time complexity: O(N), space complexity: O(1)
        reference: https://leetcode.com/problems/swap-adjacent-in-lr-string/solutions/113787/c-with-explanation-o-n-14ms/
        */
        int len = start.length();
        int i = 0, j = 0;
        while(true){
            while(i < len && start[i] == 'X'){
                i++;
            }
            while(j < len && end[j] == 'X'){
                j++;
            }
            if(i == len || j == len)
                return i == len && j == len; // if the number of 'L' and 'R' in two strings are not the same, then we will return false
            /*
            there are some examples that will return false
            1.
            XXXLXXXX
            XXXXXRXX
            2.
            XXLXXXXX
            XXXXXLXX
            3.
            XXXXXXRX
            XXXXRXXX
            */
            if(start[i] != end[j] || (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j))
                return false;
            else{
                i++;
                j++;
            }
        }
        return false;
    }
};