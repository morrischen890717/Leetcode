class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> rate;
    unordered_map<string, int> food2rate;
    unordered_map<string, string> food2cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++){
            food2rate[foods[i]] = -ratings[i];
            food2cuisine[foods[i]] = cuisines[i];
            rate[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        int old_rate = food2rate[food];
        rate[food2cuisine[food]].erase({old_rate, food});
        food2rate[food] = -newRating;
        rate[food2cuisine[food]].insert({-newRating, food});
        return;
    }
    
    string highestRated(string cuisine) {
        return rate[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */