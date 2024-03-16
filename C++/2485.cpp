class Solution {
public:
    int pivotInteger(int n) {
        // using two-pointers
        // time complexity: O(N), space complexity: O(1)
        int l = 1, r = n;
        int diff = 0;
        while(l < r){
            if(diff <= 0){
                diff += l;
                l++;
            }
            else{
                diff -= r;
                r--;
            }
        }
        return diff == 0 ? l : -1;
    }
};