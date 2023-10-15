class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices - 2 * cheeseSlices < 0 || (tomatoSlices - 2 * cheeseSlices) % 2)
            return {};
        int jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
        int small = cheeseSlices - jumbo;
        if(small < 0)
            return {};
        return {jumbo, small};
    }
};