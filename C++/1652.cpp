class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        if(k == 0)
            return vector<int> (n, 0);
        vector<int> ans(n, 0);
        int sum = 0;
        if(k > 0){
            for(int i = 0; i < n + k; i++){
                sum += code[i % n];
                if(i >= k - 1){
                    ans[(i - k + n) % n] = sum;
                    sum -= code[(i - k + 1) % n];
                }
            }
        }
        else{
            for(int i = 0; i < n - k; i++){
                sum += code[i % n];
                if(i >= -k - 1){
                    ans[(i + 1) % n] = sum;
                    sum -= code[(i + k + 1) % n];
                }
            }
        }
        return ans;
    }
};