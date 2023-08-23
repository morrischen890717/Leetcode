class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        map<string, multiset<string>> letterLogs;
        vector<string> digitLogs;
        for(string& s: logs){
            int pos = s.find(' ');
            string identifier = s.substr(0, pos);
            string content = s.substr(pos + 1);
            if(isdigit(content[0]))
                digitLogs.push_back(s);
            else
                letterLogs[content].insert(identifier);
        }
        for(map<string, multiset<string>>::iterator it = letterLogs.begin(); it != letterLogs.end(); it++){
            for(string ss: it->second){
                ans.push_back(ss + " " + it->first);
            }
        }
        for(string& ss: digitLogs){
            ans.push_back(ss);
        }
        return ans;
    }
};