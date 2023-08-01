class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for(string& cpdomain: cpdomains){
            int len = cpdomain.length();
            int space = cpdomain.find(" ");
            int times = stoi(cpdomain.substr(0, space));
            string s = cpdomain.substr(space + 1);
            cnt[s] += times;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '.')
                    cnt[s.substr(i + 1)] += times;
            }
        }
        for(unordered_map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans.push_back(to_string(it->second) + " " + it->first);
        }
        return ans;
    }
};