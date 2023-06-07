class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int len = num.length();
        vector<int> pos(10, -1);
        char prev = '0';
        for(int i = len - 1; i >= 0; i--){
            if(num[i] < prev){
                for(int j = num[i] - '0' + 1; j <= 9; j++){
                    if(pos[j] != -1){
                        swap(num[i], num[pos[j]]);
                        reverse(num.begin() + i + 1, num.end());
                        long long ans = stoll(num);
                        return (ans > INT_MAX ? -1 : ans);
                    }
                }
                return -1;
            }
            if(pos[num[i] - '0'] == -1)
                pos[num[i] - '0'] = i;
            prev = num[i];
        }
        return -1;
    }
};