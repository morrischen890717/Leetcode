class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int dis = 0;
        while(mainTank >= 5){
            dis += 5 * 10;
            mainTank -= 5;
            if(additionalTank >= 1){
                mainTank++;
                additionalTank--;
            }
        }
        dis += (mainTank * 10);
        return dis;
    }
};