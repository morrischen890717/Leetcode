class Solution {
public:
    vector<int> topologicalSort(vector<unordered_set<int>>& to, vector<int>& indegree){
        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int item = q.front();
            q.pop();
            ans.push_back(item);
            for(int next: to[item]){
                indegree[next]--;
                if(indegree[next] == 0)
                    q.push(next);
            }
        }
        if(ans.size() < indegree.size())
            return {};
        return ans;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // using topological sort
        // reference: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/solutions/1106701/c-two-level-topological-sort-peel-off-the-tricky-parts-then-do-normal-toposort/
        vector<int> ans;
        for(int& g: group){
            if(g == -1){
                g = m;
                m++;
            }
        }
        vector<unordered_set<int>> nextGroups(m), nextItems(n);
        vector<int> inGroup(m, 0), inItem(n, 0);
        for(int to = 0; to < beforeItems.size(); to++){
            int toGroup = group[to];
            for(int from: beforeItems[to]){
                int fromGroup = group[from];
                if(fromGroup != toGroup && nextGroups[fromGroup].count(toGroup) == 0){
                    nextGroups[fromGroup].insert(toGroup);
                    inGroup[toGroup]++;
                }
                if(from != to && nextItems[from].count(to) == 0){
                    nextItems[from].insert(to);
                    inItem[to]++;
                }
            }
        }
        vector<int> sortedGroups = topologicalSort(nextGroups, inGroup);
        vector<int> sortedItems = topologicalSort(nextItems, inItem);
        vector<vector<int>> v(m);
        for(int item: sortedItems){
            v[group[item]].push_back(item);
        }
        for(int g: sortedGroups){
            for(int item: v[g]){
                ans.push_back(item);
            }
        }
        return ans;
    }
};