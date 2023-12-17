class Solution {
public:
    static bool cmp(string& a, string& b){
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> v;
        for(int num: nums){
            v.push_back(to_string(num));
        }
        sort(v.begin(), v.end(), cmp);
        for(string& s: v){
            ans += s;
        }
        return ans[0] == '0' ? "0" : ans;
    }
};