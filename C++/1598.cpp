class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(string& log: logs){
            if(log == "./")
                continue;
            else if(log == "../")
                ans = max(0, ans - 1);
            else
                ans++;
        }
        return ans;
    }
};