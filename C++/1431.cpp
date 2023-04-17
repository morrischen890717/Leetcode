class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_num = *max_element(candies.begin(), candies.end());
        int diff = max_num - extraCandies;
        vector<bool> result;
        int n = candies.size();
        for(int i = 0; i < n; i++){
            if(candies[i] >= diff)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
};