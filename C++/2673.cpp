class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int cur = n / 2;
        int num = n - cur;
        int ans = 0;
        while(cur > 0){
            for(int i = cur; i < cur + num; i += 2){
                if(cost[i] < cost[i + 1]){
                    ans += (cost[i + 1] - cost[i]);
                    cost[i / 2] += cost[i + 1];
                }
                else{
                    ans += (cost[i] - cost[i + 1]);
                    cost[i / 2] += cost[i];
                }
            }
            cur /= 2;
            num /= 2;
        }
        return ans;
    }
};