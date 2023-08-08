class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int depth = -1;
        char prev;
        for(char c: s){
            if(c == '(')
                depth++;
            else{
                if(prev == '(')
                    ans += pow(2, depth);
                depth--;
            }
            prev = c;
        }
        return ans;
    }
}; 