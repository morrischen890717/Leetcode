class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for(int i = 0; (x > 1 || i == 0) && pow(x, i) < bound; i++){
            for(int j = 0; (y > 1 || j == 0) && pow(x, i) + pow(y, j) <= bound; j++){
                s.insert(pow(x, i) + pow(y, j));
            }
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};