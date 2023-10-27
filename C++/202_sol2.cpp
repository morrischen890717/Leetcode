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
        // using unordered_set
        unordered_set<int> s;
        while(n != 1){
            if(s.count(n))
                return false;
            s.insert(n);
            n = new_num(n);
        }
        return true;
    }
};