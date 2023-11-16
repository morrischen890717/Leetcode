class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // using sort and bit manipulation
        int ans = 2 * n;
        reservedSeats.push_back({INT_MAX, 0});
        int size = reservedSeats.size();
        int row = -1, reserved = 0;
        sort(reservedSeats.begin(), reservedSeats.end());
        for(int i = 0; i < size; i++){
            if(reservedSeats[i][0] != row){
                int cnt = 0;
                while(reserved){
                    cnt += (reserved & 1);
                    reserved >>= 1;
                }
                if(cnt == 3)
                    ans -= 2;
                else if(cnt == 1 || cnt == 2)
                    ans--;
                row = reservedSeats[i][0];
                reserved = 0;
            }
            if(reservedSeats[i][1] == 2 || reservedSeats[i][1] == 3)
                reserved |= (1 << 0);
            else if(reservedSeats[i][1] == 4 || reservedSeats[i][1] == 5){
                reserved |= (1 << 0);
                reserved |= (1 << 1);
            }
            else if(reservedSeats[i][1] == 6 || reservedSeats[i][1] == 7){
                reserved |= (1 << 1);
                reserved |= (1 << 2);
            }
            else if(reservedSeats[i][1] == 8 || reservedSeats[i][1] == 9)
                reserved |= (1 << 2);
        }
        return ans;
    }
};