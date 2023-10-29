class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // using math
        // reference: https://leetcode.com/problems/poor-pigs/solutions/94266/another-explanation-and-solution/?envType=daily-question&envId=2023-10-29
        int test_times = minutesToTest / minutesToDie;
        int pigs = 0;
        while(pow(test_times + 1, pigs) < buckets){
            pigs++;
        }
        return pigs;
    }
};