class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, int i, int j){
        int root_i = find(parent, i), root_j = find(parent, j);
        parent[root_i] = root_j;
        return;
    }
    bool equationsPossible(vector<string>& equations) {
        // using Union-Find
        vector<int> parent(26, 0);
        for(int i = 0; i < 26; i++){
            parent[i] = i;
        }
        for(string& e: equations){
            if(e[1] == '=')
                uni(parent, e[0] - 'a', e[3] - 'a');
        }
        for(string& e: equations){
            if(e[1] == '!' && find(parent, e[0] - 'a') == find(parent, e[3] - 'a'))
                return false;
        }
        return true;
    }
};