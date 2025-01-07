class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> s;
        int n = words.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)
                    continue;
                if(words[i].find(words[j]) != string::npos)
                    s.insert(words[j]);
            }
        }
        return vector<string> (s.begin(), s.end());
    }
};