class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        // using unordered_set
        // time complexity: O(N), space complexity: O(N)
        int n = fronts.size();
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            if(fronts[i] == backs[i])
                s.insert(fronts[i]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            if(s.count(fronts[i]) == 0)
                ans = min(ans, fronts[i]);
        }
        for(int i = 0; i < n; i++){
            if(s.count(backs[i]) == 0)
                ans = min(ans, backs[i]);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};