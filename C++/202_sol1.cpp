class Solution {
public:
    int new_num(int n){
        int sum = 0;
        while(n){
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        // using Floyd's Cycle Detection Algorithm
        // space: O(1)
        int slow = n, fast = n;
        while(slow != 1 && fast != 1){
            slow = new_num(slow);
            fast = new_num(new_num(fast));
            if(slow == fast && slow != 1)
                return false;
        }
        return true;
    }
};