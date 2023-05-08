class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        /*
        using Bézout's identity
        reference:
        https://leetcode.com/problems/water-and-jug-problem/solutions/83715/math-solution-java-solution/
        https://zh.wikipedia.org/wiki/%E8%B2%9D%E7%A5%96%E7%AD%89%E5%BC%8F
        */
        if(jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};