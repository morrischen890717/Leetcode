class Solution {
public:
    void update(map<string, int>& prev, map<string, int>& m, int cnt){
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++){
            prev[it->first] += it->second * cnt;
        }
        m = prev;
        return;
    }

    string countOfAtoms(string formula) {
        // using map and stack
        // reference: https://leetcode.com/problems/number-of-atoms/solutions/109345/java-solution-using-stack-and-map/?envType=daily-question&envId=2024-07-14
        string ans;
        map<string, int> m;
        stack<map<string, int>> st;
        int i = 0, len = formula.length();
        while(i < len){
            if(formula[i] == '('){
                st.push(m);
                m.clear();
                i++;
            }
            else if(formula[i] == ')'){
                int cnt = 0;
                i++;
                while(i < len && isdigit(formula[i])){
                    cnt = cnt * 10 + (formula[i] - '0');
                    i++;
                }
                cnt = max(1, cnt);
                map<string, int> prev = st.top();
                st.pop();
                update(prev, m, cnt);
            }
            else{
                int start = i;
                i++;
                while(i < len && islower(formula[i])){
                    i++;
                }
                string cur = formula.substr(start, i - start);
                int cnt = 0;
                while(i < len && isdigit(formula[i])){
                    cnt = cnt * 10 + (formula[i] - '0');
                    i++;
                }
                cnt = max(1, cnt);
                m[cur] += cnt;
            }
        }
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++){
            ans += it->first;
            if(it->second > 1)
                ans += to_string(it->second);
        }
        return ans;
    }
};