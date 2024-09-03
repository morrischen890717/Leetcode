class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for(char c: s){
            int num = c - 'a' + 1;
            while(num){
                sum += num % 10;
                num /= 10;
            }
        }
        k--;
        for(int i = 0; i < k; i++){
            int new_sum = 0;
            while(sum){
                new_sum += sum % 10;
                sum /= 10;
            }
            sum = new_sum;
        }
        return sum;
    }
};