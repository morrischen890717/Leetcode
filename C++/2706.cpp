class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min_1 = INT_MAX, min_2 = INT_MAX;
        for(int price: prices){
            if(price < min_1){
                min_2 = min_1;
                min_1 = price;
            }
            else if(price < min_2)
                min_2 = price;
        }
        return min_1 + min_2 > money ? money : money - (min_1 + min_2);
    }
};