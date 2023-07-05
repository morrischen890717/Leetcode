class Solution {
public:
    int flipLights(int n, int presses) {
        // reference: https://leetcode.com/problems/bulb-switcher-ii/solutions/107269/java-o-1/
        if(presses == 0)
            return 1;
        else if(n == 1)
            return 2;
        else if(n == 2 && presses == 1)
            return 3;
        else if(n == 2)
            return 4;
        else if(presses == 1)
            return 4;
        else if(presses == 2)
            return 7;
        return 8;
    }
};