class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        long long ans = 1;
        int seat_cnt = 0, plant_cnt = 0;;
        for(char c: corridor){
            if(c == 'S'){
                if(seat_cnt == 2){
                    ans *= (plant_cnt + 1);
                    ans %= MOD;
                    seat_cnt = 0;
                    plant_cnt = 0;
                }
                seat_cnt++;
            }
            else if(seat_cnt == 2)
                plant_cnt++;
        }
        return seat_cnt == 2 ? ans : 0;
    }
};