class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int n = seats.size();
        int prev = -1;
        for(int i = 0; i < n; i++){ 
            if(seats[i]){
                ans = prev == -1 ? i : max(ans, (i - prev) / 2);
                prev = i;
            }
        }
        ans = max(ans, n - prev - 1);
        return ans;
    }
};