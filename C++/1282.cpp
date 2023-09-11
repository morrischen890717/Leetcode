class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // using unordered_map and bucket
        vector<vector<int>> ans;
        int n = groupSizes.size();
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++){
            m[groupSizes[i]].push_back(i);
        }
        for(unordered_map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++){
            int i = 0;
            while(i < it->second.size()){
                vector<int> v(it->first);
                for(int j = 0; j < it->first; j++, i++){
                    v[j] = it->second[i];
                }
                ans.push_back(v);
            }
        }
        return ans;
    }
};