class Solution {
public:
    bool isSymmetric(int num){
        string s = to_string(num);
        int len = s.length();
        if(len % 2)
            return false;
        int diff = 0;
        for(int i = 0; i < len / 2; i++){
            diff += s[i] - '0';
            diff -= s[len - 1 - i] - '0';
        }
        return diff == 0;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++){
            if(isSymmetric(i))
                cnt++;
        }
        return cnt;
    }
};