class Solution {
public:
    int nextGreaterElement(int n) {
        long long ans = n;
        vector<int> cnt(10, 0);
        int prev = -1;
        while(ans){
            int digit = ans % 10;
            ans /= 10;
            cnt[digit]++;
            if(digit < prev){
                for(int j = digit + 1; j <= 9; j++){ // which digit should be placed at this position
                    if(cnt[j]){
                        ans = ans * 10 + j;
                        cnt[j]--;
                        for(int k = 0; k <= 9; k++){ // the rest part
                            while(cnt[k]){
                                ans = ans * 10 + k;
                                cnt[k]--;
                            }
                        }
                        return (ans > INT_MAX ? -1 : ans);
                    }
                }
                return -1;
            }
            prev = digit;
        }
        return -1;
    }
};