class Solution {
public:
    bool similar(string& s1, string& s2, int len){
        int cnt = 0;
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i])
                cnt++;
        }
        return (cnt == 0 || cnt == 2 ? true : false);
    }
    int get_root(vector<int>& group, int id){
        if(group[id] == id)  // reach root
            return id;
        group[id] = get_root(group, group[id]);
        return group[id];
    }
    void merge(vector<int>& group, int id1, int id2){
        int root1 = get_root(group, id1);
        int root2 = get_root(group, id2);
        if(root1 != root2)  // if root1 == root2, then two groups are already combined together
            group[root2] = root1;  // combine the two groups to one
        return;
    }
    int numSimilarGroups(vector<string>& strs) {
        /*
        using union find
        reference: https://ithelp.ithome.com.tw/articles/10209278
        */
        int n = strs.size(), len = strs[0].size();
        vector<int> group(n);
        for(int i = 0; i < n; i++){
            group[i] = i;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(similar(strs[i], strs[j], len))
                   merge(group, i, j);
            }
        }
        int group_cnt = 0;
        for(int i = 0 ; i < n; i++){
            if(group[i] == i)   // count root is enough
                group_cnt++;
        }
        return group_cnt;
    }
};