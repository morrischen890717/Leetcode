class Solution {
public:
    
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = -1;
        vector<bool> winner(n, true);
        for(vector<int>& edge: edges){
            winner[edge[1]] = false;
        }
        for(int i = 0; i < n; i++){
            if(winner[i]){
                if(ans != -1)
                    return -1;
                ans = i;
            }
        }
        return ans;
    }
};