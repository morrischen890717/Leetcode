class Solution {
public:
    int mirrorReflection(int p, int q) {
        // using math
        // reference: https://leetcode.com/problems/mirror-reflection/solutions/146336/java-solution-with-an-easy-to-understand-explanation/
        int k = p;
        while(p % q){
            p += k;
        }
        if((p / k) % 2 == 0)
            return 0;
        if((p / q) % 2)
            return 1;
        if((p / q) % 2 == 0)
            return 2;
        return -1;
    }
};