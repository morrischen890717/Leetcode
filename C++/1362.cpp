class Solution {
public:
    vector<int> closestDivisors(int num) {
        int d1 = sqrt(num + 1), d2 = sqrt(num + 2);
        int diff1 = INT_MAX, diff2 = INT_MAX;
        while((num + 1) % d1){
            d1--;
        }
        diff1 = (num + 1) / d1 - d1;
        while((num + 2) % d2){
            d2--;
        }
        diff2 = (num + 2) / d2 - d2;
        if(diff1 < diff2)
            return {d1, (num + 1) / d1};
        return {d2, (num + 2) / d2};
    }
};