class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        vector<int> mask(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].length(); j++){
                mask[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if((mask[i] & mask[j]) == 0){
                    int product = words[i].length() * words[j].length();
                    ans = max(ans, product);
                }
            }
        }
        return ans;
    }
};