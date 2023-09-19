class Solution {
public:
    int find(vector<int>& parent, int i){
        return parent[i] == i ? i : find(parent, parent[i]);
    }
    void uni(vector<int>& parent, int i, int j){
        int root_i = find(parent, i), root_j = find(parent, j);
        if(root_i < root_j)
            parent[root_j] = root_i;
        else
            parent[root_i] = root_j;
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // using Union-Find
        vector<int> parent(26, 0);
        int len = s1.length();
        for(int i = 0; i < parent.size(); i++){
            parent[i] = i;
        }
        for(int i = 0; i < len; i++){
            uni(parent, s1[i] - 'a', s2[i] - 'a');
        }
        for(char& c: baseStr){
            c = 'a' + find(parent, c - 'a');
        }
        return baseStr;
    }
};