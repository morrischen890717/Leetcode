class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        int len = blocks.length(), cnt = 0;
        for(int i = 0; i < len; i++){
            if(blocks[i] == 'B')
                cnt++;
            if(i >= k - 1){
                ans = min(ans, k - cnt);
                if(blocks[i - k + 1] == 'B')
                    cnt--;
            }
        }
        return ans;
    }
};