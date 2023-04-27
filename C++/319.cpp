class Solution {
public:
    int bulbSwitch(int n) {
        /*
        reference: https://leetcode.com/problems/bulb-switcher/solutions/3459024/python-java-c-simple-solution-one-line/
        A bulb i will only be toggled in the jth round if j is a factor of i.  
        Therefore, a bulb i will be on at the end if and only if the number of 
        factors of i is odd. A number has an odd number of factors if and only if 
        it is a perfect square.
        */
        return sqrt(n);
    }
};