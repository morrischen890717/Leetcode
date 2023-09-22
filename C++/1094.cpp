class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // using bucket
        // time complexity: O(N), space complexity: O(N)
        int n = trips.size();
        vector<int> stops(1001, 0);
        for(vector<int>& trip: trips){
            stops[trip[1]] -= trip[0];
            stops[trip[2]] += trip[0];
        }
        for(int i = 0; i <= 1000; i++){
            capacity += stops[i];
            if(capacity < 0)
                return false;
        }
        return true;
    }
};