class Solution {
public:
    void solve(unordered_map<int, vector<int>>& m, int prev, int cur, vector<int>& ans){
        ans.push_back(cur);
        for(int next: m[cur]){
            if(next != prev)
                solve(m, cur, next, ans);
        }
        return;
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // using unordered_map, unordered_set, and recursive
        // time complexity: O(N)
        vector<int> ans;
        unordered_map<int, vector<int>> m;
        unordered_set<int> isHead;
        for(vector<int>& pair: adjacentPairs){
            isHead.insert(pair[0]);
            isHead.insert(pair[1]);
            m[pair[0]].push_back(pair[1]);
            m[pair[1]].push_back(pair[0]);
            if(m[pair[0]].size() == 2)
                isHead.erase(pair[0]);
            if(m[pair[1]].size() == 2)
                isHead.erase(pair[1]);
        }
        int head = *isHead.begin();
        solve(m, INT_MIN, head, ans);
        return ans;
    }
};