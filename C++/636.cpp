class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime;
        string d = ":";
        for(string& log: logs){
            string::size_type begin = 0, it = log.find(d);
            vector<string> res;
            while(it != std::string::npos) {
                res.push_back(log.substr(begin, it - begin)); 
                begin = it + d.length();
                it = log.find(d, begin);
            }
            res.push_back(log.substr(begin));
            int id = stoi(res[0]), time = stoi(res[2]);
            string state = res[1];
            if(state == "start"){
                if(!st.empty())
                    ans[st.top()] += time - prevTime;
                st.push(id);
                prevTime = time;
            }
            else{
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }
        return ans;
    }
};