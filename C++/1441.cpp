class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int id = 0;
        vector<string> ans;
        for(int i = 1; i <= n && id < target.size(); i++){
            ans.push_back("Push");
            if(target[id] != i)
                ans.push_back("Pop");
            else
                id++;
        }
        return ans;
    }
};