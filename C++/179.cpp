class Solution {
public:
    static bool cmp(string a, string b){
        if(a + b > b + a)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        string ans;
        int n = nums.size();
        vector<string> nums_str;
        for(int i = 0; i < n; i++){
            nums_str.push_back(to_string(nums[i]));
        }
        sort(nums_str.begin(), nums_str.end(), cmp);
        if(nums_str[0] == "0")
            return "0";
        for(int i = 0; i < n; i++){
            ans += nums_str[i];
        }
        return ans;
    }
};