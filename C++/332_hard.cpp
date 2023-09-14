class Solution {
public:
    void dfs(unordered_map<string, multiset<string>>& m, string cur, vector<string>& ans){
        while(m[cur].size()){
            string next = *m[cur].begin();
            m[cur].erase(m[cur].begin());
            dfs(m, next, ans);
        }
        ans.push_back(cur);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // using DFS
        // reference: https://leetcode.com/problems/reconstruct-itinerary/solutions/78768/short-ruby-python-java-c/?envType=daily-question&envId=2023-09-14
        vector<string> ans;
        int n = tickets.size();
        unordered_map<string, multiset<string>> m; // using multiset because there might be multiple same edges
        for(vector<string>& ticket: tickets){
            m[ticket[0]].insert(ticket[1]);
        }
        dfs(m, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};