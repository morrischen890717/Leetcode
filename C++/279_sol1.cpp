class Solution {
public:
    int numSquares(int n) {
        int ans = 0;
        queue<int> q;
        q.push(n);
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                for(int j = sqrt(cur); j > 0; j--){
                    int next = cur - j * j;
                    if(next == 0)
                        return ans;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};