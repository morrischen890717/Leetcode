class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // using math
        // time complexity: O(K), space complexity: O(1)
        // we only need to iterate at most k times is because that the remainder should only be in [0, k - 1], 
        //which contains k different remainders, so if we iterate k times and still cannot find the answer, then we should return -1
        int r = 0, len = 0;
        for(int i = 0; i < k; i++){
            r = (r * 10 + 1) % k;
            len++;
            if(r == 0)
                return len;
        }
        return -1;
    }
};