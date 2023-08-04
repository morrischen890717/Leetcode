class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string ans;
        unordered_map<int, int> m;
        for(int i = 0; i < indices.size(); i++){
            m[indices[i]] = i;
        }
        for(int i = 0; i < s.length(); i++){
            if(m.count(i) > 0){
                string source = sources[m[i]];
                bool same = true;
                if(s.length() - i < source.length())
                    continue;
                for(int j = 0; j < source.length(); j++){
                    if(s[i + j] != source[j]){
                        same = false;
                        break;
                    }
                }
                if(same){
                    ans += targets[m[i]];
                    i += (source.length() - 1);
                }
                else
                    ans += s[i];
            }
            else
                ans += s[i];
        }
        return ans;
    }
};