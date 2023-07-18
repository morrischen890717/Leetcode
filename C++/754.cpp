class Solution {
public:
    int reachNumber(int target) {
        // reference: https://leetcode.com/problems/reach-a-number/solutions/112968/short-java-solution-with-explanation/
        target = abs(target);
        int sum = 0;
        int curNum = 1;
        while(sum < target){
            sum += curNum;
            curNum++;
        }
        while((sum - target) % 2){
            sum += curNum;
            curNum++;
        }
        return curNum - 1;
    }
};