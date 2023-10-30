class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // using priority_queue
        priority_queue<pair<int, int>> pq;
        for(vector<int>& restaurant: restaurants){
            if((veganFriendly == 1 && restaurant[2] == 0) || restaurant[3] > maxPrice || restaurant[4] > maxDistance)
                continue;
            else
                pq.push({restaurant[1], restaurant[0]});
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};