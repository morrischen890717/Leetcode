class Solution {
public:
    int find(unordered_map<int, int>& parent, int& island, int i){
        if(parent.count(i) == 0){
            parent[i] = i;
            island++;
        }
        return parent[i] == i ? i : find(parent, island, parent[i]);
    }
    void uni(unordered_map<int, int>& parent, int& island, int i, int j){
        int parentI = find(parent, island, i), parentJ = find(parent, island, j);
        if(parentI != parentJ){
            parent[parentI] = parentJ;
            island--;
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        // using Union-Find
        // reference: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/solutions/197668/count-the-number-of-islands-o-n/
        int n = stones.size(), island = 0;
        unordered_map<int, int> parent;
        for(int i = 0; i < n; i++){
            uni(parent, island, stones[i][0], stones[i][1] + 10001);
        }
        return n - island;
    }
};