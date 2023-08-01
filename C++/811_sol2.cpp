class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> cnt;
        vector<string> ans;
        for(string& cpdomain: cpdomains){
            int len = cpdomain.length();
            vector<string> v;
            char *d = " .";
            char *s = new char[len + 1];  // char array
            strcpy(s, cpdomain.c_str()); // convert cpdomain into char array so that strtok could be used
            char *p = strtok(s, d);
            int times = stoi(p);
            p = strtok(NULL, d);
            while (p != NULL) {
                v.push_back(p);
                p = strtok(NULL, d);	   
            }
            string suffix = "";
            for(int i = v.size() - 1; i >= 0; i--){
                suffix = suffix == "" ? v[i] : v[i] + "." + suffix;
                cnt[suffix] += times;
            }
        }
        for(unordered_map<string, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            ans.push_back(to_string(it->second) + " " + it->first);
        }
        return ans;
    }
};