class Solution {
public:
    string find(unordered_map<string, string>& parent, string cur){
        return parent[cur] == cur ? cur : find(parent, parent[cur]);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<string>> ans;
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> unions;
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        for(int i = 0; i < n; i++){
            string root = find(parent, accounts[i][1]);
            for(int j = 2; j < accounts[i].size(); j++){
                parent[find(parent, accounts[i][j])] = root;
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                unions[find(parent, accounts[i][j])].insert(accounts[i][j]);
            }
        }
        for(unordered_map<string, set<string>>::iterator it = unions.begin(); it != unions.end(); it++){
            vector<string> v(it->second.begin(), it->second.end());
            v.insert(v.begin(), owner[it->first]);
            ans.push_back(v);
        }
        return ans;
    }
};