class Solution {
public:
    int brokenCalc(int startValue, int target) {
        /*
        using math and Greedy
        reference: https://leetcode.com/problems/broken-calculator/solutions/234484/java-c-python-change-y-to-x-in-1-line/
        main idea:
        If target <= startValue, we will increase target until target == startValue.
        If target > startValue,
            if target is odd, we can only do target+=1 (because any number times 2 is even but not odd, contradiction.)
            if target is even, we will do target/=2, because (target+1+1)/2 = target/2+1, 
            which costs 3 operations on the left side while it just costs only 2 operations on the right side, 
            so we will always do target/=2 if target is even.
        */
        int ans = 0;
        while(target > startValue){
            target = target % 2 ? target + 1 : target / 2;
            ans++;
        }
        ans += (startValue - target);
        return ans;
    }
};