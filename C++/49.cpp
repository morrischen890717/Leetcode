class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> cnt;
        for(string& str: strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            cnt[tmp].push_back(str);
        }
        for(unordered_map<string, vector<string>>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans.push_back(it->second);
        }
        return ans;
    }
};