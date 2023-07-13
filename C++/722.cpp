class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string cur = "";
        bool state = false; // if "/*" starts, then turn state to true
        for(string& s: source){
            for(int i = 0; i < s.length(); i++){
                if(state){
                    if(s[i] == '*' && i < s.length() - 1 && s[i + 1] == '/'){
                        state = false;
                        i++;
                    }
                }
                else{
                    if(s[i] == '/' && i < s.length() - 1 && s[i + 1] == '/')
                        break;
                    else if(s[i] == '/' && i < s.length() - 1 && s[i + 1] == '*'){
                        state = true;
                        i++;
                    }
                    else
                        cur += s[i];
                }
            }
            if(!state && cur != ""){
                ans.push_back(cur);
                cur = "";
            }
        }
        return ans;
    }
};