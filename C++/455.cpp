class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int children = g.size(), cookie = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for(int j = 0; j < cookie && i < children; j++){
            if(g[i] <= s[j])
                i++;
        }
        return i;
    }
};