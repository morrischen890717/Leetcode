class Solution {
public:
    int find(vector<int>& parent, int i){
        return i == parent[i] ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, vector<int>& rank, int i, int j){
        int parent_i = find(parent, i), parent_j = find(parent, j);
        if(parent_i == parent_j)
            return;
        if(rank[parent_i] < rank[parent_j]){
            parent[parent_i] = parent_j;
            rank[parent_j]++;
        }
        else{
            parent[parent_j] = parent_i;
            rank[parent_i]++;
        }
        return;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // using Union-Find(union by rank)
        // reference: https://leetcode.com/problems/smallest-string-with-swaps/solutions/388257/c-with-picture-union-find/
        string ans(s);
        int n = s.length();
        vector<int> parent(n), rank(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        for(vector<int>& pair: pairs){
            uni(parent, rank, pair[0], pair[1]);
        }
        vector<vector<int>> group(n);
        for(int i = 0; i < n; i++){
            group[find(parent, i)].push_back(i);
        }
        for(int i = 0; i < n; i++){
            string ss = "";
            for(int j = 0; j < group[i].size(); j++){
                ss += s[group[i][j]];
            }
            sort(ss.begin(), ss.end());
            for(int j = 0; j < group[i].size(); j++){
                ans[group[i][j]] = ss[j];
            }
        }
        return ans;
    }
};